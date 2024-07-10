gaudi_add_library(GaudiSimpleProjectLib
                  SOURCES src/Lib/FourMomentum.cpp
                  LINK PUBLIC Gaudi::GaudiKernel)

gaudi_add_module(Examples
                SOURCES src/GaudiSimpleProject/MomentumGeneratorAlg.cpp
                src/GaudiSimpleProject/MomentumProcessorAlg.cpp
                LINK Gaudi::GaudiKernel
                     Gaudi::GaudiAlgLib
                     Gaudi::GaudiUtilsLib
                     GaudiSimpleProjectLib
                     DetectorDescriptionInterfaces
                )


 
