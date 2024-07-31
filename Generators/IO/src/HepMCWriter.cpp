#include <ctime>
#include <map>

#include "HepMC3/WriterRootTree.h"
#include "HepMC3/WriterAscii.h"

#include "HepMCWriter.h"


static bool ends_with(const std::string& str, const std::string& suffix){
  return str.size() >= suffix.size() && str.compare(str.size()-suffix.size(), suffix.size(), suffix) == 0;
}

HepMCWriter::HepMCWriter(const std::string& name, ISvcLocator* svcloc) : 
  base_class(name, svcloc) {}

StatusCode HepMCWriter::initialize()
{ 
  StatusCode status;
  status = Service::initialize();
  if (!status.isSuccess()) { return status; }
  status = initializeOutputFile();
  if (!status.isSuccess()) { return status; }
  m_workerThread = std::thread(&HepMCWriter::workerThread, this);
  return StatusCode::SUCCESS;
}

StatusCode HepMCWriter::finalize()
{
  m_taskQueue.emplace([this]() { this->m_isActive = false; });
  m_workerThread.join();
  m_outputFile->close();
  return StatusCode::SUCCESS;
}

void HepMCWriter::writeEvent(std::shared_ptr<HepMC3::GenEvent> eventPtr)
{
  m_taskQueue.emplace([this, eventPtr]() { this->i_writeEvent(eventPtr); });
}

StatusCode HepMCWriter::initializeOutputFile()
{
  std::map<std::string, std::pair<std::string, std::function<std::shared_ptr<HepMC3::Writer>(const std::string&)>>> factory = 
    {
      {"ROOTTree", {".root", [](const std::string& name){ return std::make_shared<HepMC3::WriterRootTree>(name); }}},
      {"Ascii", {".dat", [](const std::string& name){ return std::make_shared<HepMC3::WriterAscii>(name); }}}
    };

  std::string name;

  auto it = factory.find(m_outputFormat.value());
  if(it != factory.end())
  {
    if(!ends_with(m_outputPath.value(), it->second.first)){
      warning() << "For " << it->first << " output file must end with " << it->second.first << endmsg;
      name = generateDefaultOutputPath(it->second.first);
    } else {
      name = m_outputPath.value();
    }
    m_outputFile = it->second.second(name);
    if (m_outputFile->failed()){
      error() << "Output file creation error" << endmsg;
      return StatusCode::FAILURE;
    }
  }
  else
  {
    error() << "Wrong output format: " + m_outputFormat.value() << endmsg; 
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

std::string HepMCWriter::generateDefaultOutputPath(const std::string& suffix)
{
  std::time_t t = std::time(nullptr);
  char mbstr[20];
  std::strftime(mbstr, sizeof(mbstr), "%d.%m.%Y-%H:%M:%S", std::localtime(&t));
  std::string ans = mbstr + suffix;
  warning() << "Default name " << ans << " was generated" << endmsg;
  return ans;
}

void HepMCWriter::i_writeEvent(std::shared_ptr<HepMC3::GenEvent> eventPtr)
{
  m_outputFile->write_event(*eventPtr);
  if(m_outputFile->failed())
  {
    throw GaudiException("HepMCWriter Error on attenpt to write", "HepMCWriter Error", StatusCode::FAILURE);
  }
}

void HepMCWriter::workerThread()
{
  m_isActive = true;
  std::function<void()> task;
  while (m_isActive)
  {
    m_taskQueue.pop(task);
    task();
  }
}

DECLARE_COMPONENT(HepMCWriter)
