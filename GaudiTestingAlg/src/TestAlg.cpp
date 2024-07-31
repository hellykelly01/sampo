#include "TestAlg.h"
// #include "GaudiKernel/Message.h"


DECLARE_COMPONENT(TestAlg)

// constructor
TestAlg::TestAlg(const std::string& name, ISvcLocator* ploc) : 
  Algorithm(name, ploc)
  ,logMgr("TestAlg", m_logsvc)
  {}

// initialize
StatusCode TestAlg::initialize() {
  
  return StatusCode::SUCCESS;
}

// execute
StatusCode TestAlg::execute() {
 std::shared_ptr<HepMC3::GenEvent> event = std::make_shared<HepMC3::GenEvent>(HepMC3::Units::GEV, HepMC3::Units::MM);
  m_hepmcWriter->writeEvent(event);
  logMgr.info() << "motherfucker" << endmsg;
  return StatusCode::SUCCESS;
}

// finalize
StatusCode TestAlg::finalize() {
  return StatusCode::SUCCESS;
}

