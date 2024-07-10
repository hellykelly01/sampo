#ifndef GEOMODELSVC_H
#define GEOMODELSVC_H

#include "IGeoModelSvc.h"
#include "GaudiKernel/Service.h"
#include "GeoModelDBManager/GMDBManager.h"
#include "GeoModelRead/ReadGeoModel.h"
#include "GeoModelKernel/GeoFullPhysVol.h"
#include "GeoModelKernel/GeoNameTag.h"

#include <string>
#include <iostream>
#include <memory>
#include <fstream>

class GeoModelSvc : public extends<Service, IGeoModelSvc> {
public:
  using extends::extends;

  StatusCode initialize() override;
  StatusCode finalize() override;

  void printAllDBTables() const override;
  const GeoVPhysVol* getPhysWorld() const override{ return world; }

private:
  Gaudi::Property<std::string> m_dbpath{this, "m_dbpath", "/cvmfs/nica.jinr.ru/spd/gaudi/GeoModel/MyProject/cubik.db"};
  // shared_ptr for auto-delete
  std::shared_ptr<GMDBManager> db;
  // raw pointer, don't need to delet as it's managed by it's class
  const GeoVPhysVol* world;
};


#endif