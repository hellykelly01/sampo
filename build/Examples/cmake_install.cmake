# Install script for directory: /cvmfs/nica.jinr.ru/spd/gaudi/sampo/Examples

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/cvmfs/nica.jinr.ru/spd/external/binutils/2.37/x86_64-centos7-gcc11-opt/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/Examples/libGaudiSimpleProjectLib.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so"
         OLD_RPATH "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/.plugins:/cvmfs/nica.jinr.ru/spd/gaudi/v36r9/lib:/cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/tbb/2020-U2/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/fmt/7.1.3/x86_64-centos7-gcc11-opt/lib64:/cvmfs/nica.jinr.ru/spd/external/Python/3.9.6/x86_64-centos7-gcc11-opt/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/nica.jinr.ru/spd/external/binutils/2.37/x86_64-centos7-gcc11-opt/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libGaudiSimpleProjectLib.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/Examples/include/")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE MODULE FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/Examples/libExamples.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so"
         OLD_RPATH "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/.plugins:/cvmfs/nica.jinr.ru/spd/gaudi/v36r9/lib:/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/Examples:/cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/tbb/2020-U2/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/fmt/7.1.3/x86_64-centos7-gcc11-opt/lib64:/cvmfs/nica.jinr.ru/spd/external/Python/3.9.6/x86_64-centos7-gcc11-opt/lib:/cvmfs/nica.jinr.ru/spd/external/GeoModel/5.3.0/x86_64-centos7-gcc11-opt/lib64:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/cvmfs/nica.jinr.ru/spd/external/binutils/2.37/x86_64-centos7-gcc11-opt/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libExamples.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/sampo.components")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/python/Examples" TYPE FILE FILES
    "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/Examples/genConfDir/Examples/ExamplesConf.py"
    "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/Examples/genConfDir/Examples/__init__.py"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/sampo.confdb")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE FILE FILES "/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/sampo.confdb2")
endif()
