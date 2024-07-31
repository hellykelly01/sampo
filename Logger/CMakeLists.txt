include_directories(${P7_Headers})

gaudi_add_library(Logger
    SOURCES
      src/Lib/LogSvc.cpp
      src/Lib/P7Logger.cpp
      src/Lib/P7LogSvc.cpp
      src/components/LogStream.cpp
      src/components/LogStreamMgr.cpp
    LINK
      Gaudi::GaudiKernel
      libp7-baical::P7
)

