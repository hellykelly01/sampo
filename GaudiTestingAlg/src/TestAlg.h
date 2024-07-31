#ifndef TESTALG_H
#define TESTALG_H

// includes
#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/ServiceHandle.h"
#include "ILogSvc.h"
#include "LogStreamMgr.h"
#include "IHepMCWriter.h"
#include "HepMC3/GenEvent.h"

//  #include <memory>

/* Simple Algorithm for testing purposes */
class TestAlg : public Algorithm{
public:
  TestAlg(const std::string& name, ISvcLocator* pSvcLocator);
  StatusCode initialize() override;
  StatusCode execute() override;
  StatusCode finalize() override;
private:
  ServiceHandle<ILogSvc> m_logsvc{this, "P7LogSvc", "P7LogSvc", ""};
  ServiceHandle<IHepMCWriter> m_hepmcWriter{this, "HepMCWriter", "HepMCWriter", ""};
  LogStreamMgr logMgr;
};

#endif // TESTALG_H
