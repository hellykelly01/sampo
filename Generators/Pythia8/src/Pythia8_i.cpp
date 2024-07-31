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

  return StatusCode::SUCCESS;
}

// execute
StatusCode Pythia8_i::execute() {
  StatusCode status = callGen();
  if (!status.isSuccess()) { return status; }
  Pythia8Event* ev = new Pythia8Event;
  ev->SetEvent(m_pythia.event);
  // info() << m_pythia.event.size() << endmsg;
  // status = eventSvc()->registerObject("/Event/1", ev);
  // if (!status.isSuccess()) { return status; }

  std::shared_ptr<HepMC3::GenEvent> eventPtr = std::make_shared<HepMC3::GenEvent>(HepMC3::Units::GEV, HepMC3::Units::MM);
  m_pythiaToHepMC.fill_next_event(m_pythia.event, eventPtr.get(), -1, &m_pythia.info);
  hepmc()->writeEvent(eventPtr);
  return StatusCode::SUCCESS;
}

// finalize
StatusCode Pythia8_i::finalize() {
  m_pythia.stat();
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
