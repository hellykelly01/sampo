#ifndef IHEPMCWRITER_H
#define IHEPMCWRITER_H

#include <memory>

#include "GaudiKernel/IInterface.h"

#include "HepMC3/GenEvent.h"

class IHepMCWriter : virtual public IInterface{
public:
  DeclareInterfaceID(IHepMCWriter, 1, 0);
  virtual void writeEvent(std::shared_ptr<HepMC3::GenEvent>) = 0;
};

#endif