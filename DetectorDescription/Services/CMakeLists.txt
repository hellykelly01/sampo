gaudi_add_module(DetectorDescriptionSvcs
                 SOURCES 
                         GeoModelSvc/GeoModelSvc.cpp
                
                 LINK Gaudi::GaudiKernel
                      DetectorDescriptionInterfaces
                      GeoModelCore::GeoModelKernel
                      GeoModelIO::GeoModelDBManager
                      GeoModelIO::GeoModelRead
                      )
          
      
               

