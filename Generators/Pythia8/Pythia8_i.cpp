#include "Pythia8_i.h"

DECLARE_COMPONENT(Pythia8_i)

// constructor
Pythia8_i::Pythia8_i(const std::string& name, ISvcLocator* ploc) : Algorithm(name, ploc) {}

// initialize
StatusCode Pythia8_i::initialize() {
  StatusCode status;

  // Setting RndmGen for Pythia8
  if(m_useRndmGenSvc.value()){

    warning() << " !!!!!!!!!!!!  WARNING ON PYTHIA RANDOM NUMBERS !!!!!!!!!! "  << endmsg;
    warning() << "                   Gaudi RndmGenSvc IS USED."  << endmsg;
    warning() << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! "  << endmsg;

    m_customRndm = std::make_shared<customRndm>();
    status = m_customRndm->init(randSvc());
    if (!status.isSuccess()) { return status; }
    m_pythia.setRndmEnginePtr(m_customRndm);
    
  }else{
    warning() << " !!!!!!!!!!!!  WARNING ON PYTHIA RANDOM NUMBERS !!!!!!!!!! " << endmsg;
    warning() << "    THE STANDARD PYTHIA8 RANDOM NUMBER GENERATOR IS USED." << endmsg;
    warning() << " !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endmsg;
  }

  // Setting Pythia8 via file
  if(!m_pythia.readFile(m_settingsPath.value())){ 
    error() << "Error while m_pythia.readFile(" + m_settingsPath.value() + ")" << endmsg;
    return StatusCode::FAILURE; 
  }

  if(!m_pythia.init()){ 
    error() << "Error while m_pythia.init()" << endmsg;
    return StatusCode::FAILURE; 
  } 

  // Setting output file
  status = initializeOutputFile();
  if (!status.isSuccess()) { return status; }

  return StatusCode::SUCCESS;
}

// execute
StatusCode Pythia8_i::execute() {
  StatusCode status = callGen();
  if (!status.isSuccess()) { return status; }
  Pythia8Event* ev = new Pythia8Event;
  ev->SetEvent(m_pythia.event);
 // info() << m_pythia.event.size() << endmsg;
  status = eventSvc()->registerObject("/Event/1", ev);
  if (!status.isSuccess()) { return status; }

  HepMC3::GenEvent hepmc( HepMC3::Units::GEV, HepMC3::Units::MM );
  m_pythiaToHepMC.fill_next_event(m_pythia.event, &hepmc, -1, &m_pythia.info);
  m_outputFile->write_event(hepmc);
  if (m_outputFile->failed()){
    error() << "error while writing event" << endmsg;
    return StatusCode::FAILURE;
  }

  return StatusCode::SUCCESS;
}

// finalize
StatusCode Pythia8_i::finalize() {
  m_pythia.stat();
  m_outputFile->close();
  return StatusCode::SUCCESS;
}

// callGen /*add re-seeding here*/
StatusCode Pythia8_i::callGen() {
  if(!m_pythia.next()){
    ++m_failureCount;
    if(m_failureCount >= m_maxFailures){
      error() << "Exceeded the max number of consecutive event failures" << endmsg;
      m_failureCount = 0;
      return StatusCode::FAILURE;
    }else{
      info() << "Event generation failed - re-trying" << endmsg;
      return callGen();
    }
  }
  m_failureCount = 0;
  return StatusCode::SUCCESS;
}

// initializeOutputFile
StatusCode Pythia8_i::initializeOutputFile(){
  std::string name;
  if (m_outputFormat.value() == "ROOTTree"){
    if(!ends_with(m_outputPath.value(), ".root")){
      warning() << "For ROOTTree output file must end with .root" << endmsg;
      name = generateDefaultOutputFileName(".root");
    } else {
      name = m_outputPath.value();
    }
    m_outputFile = std::make_shared<HepMC3::WriterRootTree>(name);
  } else if (m_outputFormat.value() == "Ascii"){
    if(!ends_with(m_outputPath.value(), ".dat")){
      warning() << "For Ascii output file must end with .dat" << endmsg;
      name = generateDefaultOutputFileName(".dat");
    } else {
      name = m_outputPath.value();
    }
    m_outputFile = std::make_shared<HepMC3::WriterAscii>(name);
  } else {
    error() << "Wrong output format: " + m_outputFormat.value() << endmsg; 
    return StatusCode::FAILURE;
  }

  if (m_outputFile->failed()){
    error() << "Output file creation error" << endmsg;
    return StatusCode::FAILURE;
  }
  return StatusCode::SUCCESS;
}

// generateDefaultOutputName
std::string Pythia8_i::generateDefaultOutputFileName(const std::string& suffix){
  std::time_t t = std::time(nullptr);
    char mbstr[20];
    std::strftime(mbstr, sizeof(mbstr), "%d.%m.%Y-%H:%M:%S", std::localtime(&t));
    std::string ans = std::string("Pythia") + std::to_string(PYTHIA_VERSION).substr(0,5) + "_";
    ans = ans + mbstr + suffix;
    warning() << "Default name " << ans << " was generated" << endmsg;
    return ans;
}