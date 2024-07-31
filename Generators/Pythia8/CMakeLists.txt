gaudi_add_module(Pythia8Generator
               SOURCES src/Pythia8_i.cpp 
               LINK Gaudi::GaudiKernel
                    Pythia8
                    HepMC3::HepMC3 
                    HepMCIO
                )