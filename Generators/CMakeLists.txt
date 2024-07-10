gaudi_add_module(Generators
               SOURCES Pythia8/Pythia8_i.cpp 
               LINK Gaudi::GaudiKernel
                    Gaudi::GaudiAlgLib
                    Gaudi::GaudiUtilsLib
                    Pythia8
                    ROOT::Tree
                    ROOT::RIO 
                    ROOT::Core 
                    HepMC3::HepMC3 
                    HepMC3::rootIO
                )