# Boost
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/cmake/

# nlohmann_json
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/json/3.9.1/lib64/cmake/

# TBB
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/tbb/2020-U2/x86_64-centos7-gcc11-opt/lib/cmake/

# fmt
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/fmt/7.1.3/x86_64-centos7-gcc11-opt/lib64/cmake/

# HepMC3
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/HepMC3/hepmc3-install/share/HepMC3/cmake/

# GeoModel
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/external/GeoModel/5.3.0/x86_64-centos7-gcc11-opt/lib/cmake/:/cvmfs/nica.jinr.ru/spd/external/GeoModel/5.3.0/x86_64-centos7-gcc11-opt/lib64/cmake/

# p7
CMAKE_PREFIX_PATH=$CMAKE_PREFIX_PATH:/cvmfs/nica.jinr.ru/spd/gaudi/p7/install/lib/libp7-baical

export CMAKE_PREFIX_PATH

cmake -DZLIB_ROOT=/cvmfs/nica.jinr.ru/spd/external/zlib/1.2.11/x86_64-centos7-gcc11-opt/                     \
      -DRANGEV3_INCLUDE_DIR=/cvmfs/nica.jinr.ru/spd/external/rangev3/0.11.0/x86_64-centos7-gcc11-opt/include \
      -DCPPGSL_INCLUDE_DIR=/cvmfs/nica.jinr.ru/spd/external/cppgsl/3.1.0/x86_64-centos7-gcc11-opt/include    \
      -DAIDA_INCLUDE_DIRS=/cvmfs/nica.jinr.ru/spd/external/AIDA/3.2.1/x86_64-centos7-gcc11-opt/src/cpp       \
      -DPYTHIA8_ROOT_DIR=/cvmfs/nica.jinr.ru/spd/external/Pythia/8.311/x86_64-centos7-gcc11-opt              \
..