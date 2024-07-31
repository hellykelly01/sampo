#ifndef HEPMCWRITER_H
#define HEPMCWRITER_H

#include <string>
#include <thread>
#include <functional>

#include "HepMC3/Writer.h"
#include "tbb/concurrent_queue.h"

#include "GaudiKernel/Service.h"
#include "IHepMCWriter.h"

class HepMCWriter : public  extends<Service, IHepMCWriter>{
public:
  HepMCWriter(const std::string& name, ISvcLocator* svcloc);
  HepMCWriter(const HepMCWriter& other) = delete;
  StatusCode initialize() override;
  StatusCode finalize() override;
  void writeEvent(std::shared_ptr<HepMC3::GenEvent> eventPtr) override;
private:
  StatusCode initializeOutputFile();
  std::string generateDefaultOutputPath(const std::string& suffix);
  void i_writeEvent(std::shared_ptr<HepMC3::GenEvent> eventPtr);
  void workerThread();

  std::shared_ptr<HepMC3::Writer> m_outputFile;
  tbb::concurrent_bounded_queue<std::function<void()>> m_taskQueue;
  std::thread m_workerThread;
  bool m_isActive{false};

  Gaudi::Property<std::string> m_outputFormat{this, "outputFormat", "Ascii", ""};
  Gaudi::Property<std::string> m_outputPath{this, "outputPath", "", ""};
};

#endif