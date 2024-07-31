#ifndef PYTHIA8ALG_H
#define PYTHIA8ALG_H

#include <memory>
#include <string>
#include <ctime>

#include "GaudiKernel/Algorithm.h"
#include "GaudiKernel/RndmGenerators.h"
#include "GaudiKernel/DataObject.h"
#include "Pythia8/Pythia.h"
#include "Pythia8Plugins/HepMC3.h"
#include "HepMC3/GenEvent.h"
#include "GaudiKernel/ServiceHandle.h"
#include "IHepMCWriter.h"


// Custom RndmGen for Pythia8
class customRndm : public Pythia8::RndmEngine {
public:
  customRndm() {}
  // Only thing that will be used by Pythia
  double flat(){
    return m_numbers();
  }
  StatusCode init(const SmartIF<IRndmGenSvc>& svc) {
    return m_numbers.initialize(svc, Rndm::Flat(0, 1));
  }
private:
  Rndm::Numbers m_numbers;
};

// DataObject wrapper for Pythia8::Event
class Pythia8Event : public DataObject{
public:
  Pythia8Event(){}
  void SetEvent(const Pythia8::Event& other){ event = other; }
  Pythia8::Event& GetEvent(){ return event ;}
private:
  Pythia8::Event event;
};

// Pythia8 Algorithm
class Pythia8_i : public Algorithm{
public:
  Pythia8_i(const std::string& name, ISvcLocator* pSvcLocator);

  StatusCode initialize() override;
  StatusCode execute() override;
  StatusCode finalize() override;

  StatusCode callGen();
  ServiceHandle<IHepMCWriter>& hepmc() { return m_hepmcWriter; }

private:
  Pythia8::Pythia m_pythia;
  HepMC3::Pythia8ToHepMC3 m_pythiaToHepMC;

  std::shared_ptr<customRndm> m_customRndm;
  int m_failureCount = 0;

  // Properties
  Gaudi::Property<bool> m_useRndmGenSvc{this, "useRndmGenSvc", true};
  Gaudi::Property<std::string> m_settingsPath{this, "pythiaSettingsPath", ""};
  Gaudi::Property<int> m_maxFailures{this, "MaxFailures", 10};

  ServiceHandle<IHepMCWriter> m_hepmcWriter{this, "HepMCWriter", "HepMCWriter", ""};
};

#endif