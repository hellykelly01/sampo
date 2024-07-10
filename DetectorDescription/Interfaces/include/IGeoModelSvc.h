#ifndef IGEOMODELSVC_H
#define IGEOMODELSVC_H

#include "GaudiKernel/IInterface.h"
#include "GeoModelKernel/GeoPhysVol.h"

class IGeoModelSvc : virtual public IInterface {
public:
  /// InterfaceID
  DeclareInterfaceID(IGeoModelSvc, 1, 0);

  virtual void printAllDBTables() const = 0;
  virtual const GeoVPhysVol* getPhysWorld() const = 0;
};


#endif