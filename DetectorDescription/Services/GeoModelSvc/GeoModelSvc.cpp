#include "GaudiKernel/MsgStream.h"
#include "GeoModelSvc.h"

StatusCode GeoModelSvc::initialize() {
  StatusCode status = Service::initialize();
  if (status.isFailure()) {
    error() << "Could not initialize main svc" << endmsg;
  }
  std::ifstream infile(m_dbpath.value().c_str());
	if (!infile.good()) {
		info() << "\n\tERROR!! A '" << m_dbpath.value()
		<< "' file does not exist!! Please, check the path of the "
		"input file before running this program." << endmsg;
		status = StatusCode::FAILURE;
	}
	infile.close();
	
	// open the DB
	db = std::make_shared<GMDBManager>(m_dbpath.value());
	/* Open database */
	if (db->checkIsDBOpen()) {
		info() << "OK! Database is open!" << endmsg;
	} else {
		info() << "Database is not open!" << endmsg;
		status =  StatusCode::FAILURE;
	}

	if (status.isFailure()) {
    return status;
  }

	/* setup the GeoModel reader */
	
	GeoModelIO::ReadGeoModel readInGeo = GeoModelIO::ReadGeoModel(db.get());
	info() << "ReadGeoModel set." << endmsg;
	
	/* build the GeoModel geometry */
	
	world = readInGeo.buildGeoModel();  // builds the whole GeoModel tree in memory
                                  		// and get an handle to the 'world' volume

	info() << "ReadGeoModel::buildGeoModel() done." << endmsg;

	// --- testing the imported geometry
	// get the GeoLogVol used for the 'world' volume
	info() << "Getting the GeoLogVol used by the 'world' volume" << endmsg;
	const GeoLogVol* logVol = world->getLogVol();
	info() << "'world' GeoLogVol name: " << logVol->getName() << endmsg;
	info() << "'world' GeoMaterial name: " << logVol->getMaterial()->getName() << endmsg;
	// get number of children volumes
	unsigned int nChil = world->getNChildVols();
	info() << "'world' number of children: " << nChil << endmsg;
	// loop over all children nodes
	info() << "Looping over all 'volume' children (i.e., GeoPhysVol and "
                 "GeoFullPhysVol)..."
              << endmsg;
	for (unsigned int idx = 0; idx < nChil; ++idx) {
		PVConstLink nodeLink = world->getChildVol(idx);
		if (dynamic_cast<const GeoVPhysVol*>(&(*(nodeLink)))) {
			info() << "\t" << "the child n. " << idx << " " << endmsg;
			const GeoVPhysVol* childVolV = &(*(nodeLink));
			if (dynamic_cast<const GeoPhysVol*>(childVolV)) {
				const GeoPhysVol* childVol = dynamic_cast<const GeoPhysVol*>(childVolV);
				info() << "is a GeoPhysVol, whose GeoLogVol name is: " << childVol->getLogVol()->getName() << endmsg;
				info() << " and it has  " << childVol->getNChildVols() << " child volumes\n" << endmsg;
			}
			else if (dynamic_cast<const GeoFullPhysVol*>(childVolV)) {
				const GeoFullPhysVol* childVol = dynamic_cast<const GeoFullPhysVol*>(childVolV);	
				info() << "is a GeoFullPhysVol, whose GeoLogVol name is: " << childVol->getLogVol()->getName() << endmsg;		
				info() << " and it has  " << childVol->getNChildVols() << " child volumes\n" << endmsg;			
			}
		} else if (dynamic_cast<const GeoNameTag*>(&(*(nodeLink)))) {
			info() << "\t" << "the child n. " << idx << " is a GeoNameTag\n" << endmsg;
			const GeoNameTag* childVol = dynamic_cast<const GeoNameTag*>(&(*(nodeLink)));
			info() << "\t\tGeoNameTag's name: " << childVol->getName() << endmsg;
		}
	}
  return status;
}

void GeoModelSvc::printAllDBTables() const {
	if(!db){
		info() << "No input DB provided." << endmsg;
		return;
	}
  info() << "\n=== Printing the list of all tables in the input DB:" << endmsg;
	db->printAllDBTables();
}

StatusCode GeoModelSvc::finalize(){
  StatusCode status = Service::finalize();
  if (status.isFailure()) {
    error() << "Could not finalize main svc" << endmsg;
    return StatusCode::FAILURE;
  }
  return status;
}

DECLARE_COMPONENT(GeoModelSvc)