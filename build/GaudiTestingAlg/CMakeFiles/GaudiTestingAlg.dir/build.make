# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cvmfs/nica.jinr.ru/spd/external/CMake/3.20.0/x86_64-centos7-gcc11-opt/bin/cmake

# The command to remove a file.
RM = /cvmfs/nica.jinr.ru/spd/external/CMake/3.20.0/x86_64-centos7-gcc11-opt/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cvmfs/nica.jinr.ru/spd/gaudi/sampo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build

# Include any dependencies generated for this target.
include GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/compiler_depend.make

# Include the progress variables for this target.
include GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/progress.make

# Include the compile flags for this target's objects.
include GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/flags.make

GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o: GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/flags.make
GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o: ../GaudiTestingAlg/src/TestAlg.cpp
GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o: GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o"
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && /cvmfs/nica.jinr.ru/spd/external/gcc/11.3.0/x86_64-centos7-gcc11-opt/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o -MF CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o.d -o CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o -c /cvmfs/nica.jinr.ru/spd/gaudi/sampo/GaudiTestingAlg/src/TestAlg.cpp

GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.i"
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && /cvmfs/nica.jinr.ru/spd/external/gcc/11.3.0/x86_64-centos7-gcc11-opt/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cvmfs/nica.jinr.ru/spd/gaudi/sampo/GaudiTestingAlg/src/TestAlg.cpp > CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.i

GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.s"
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && /cvmfs/nica.jinr.ru/spd/external/gcc/11.3.0/x86_64-centos7-gcc11-opt/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cvmfs/nica.jinr.ru/spd/gaudi/sampo/GaudiTestingAlg/src/TestAlg.cpp -o CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.s

# Object files for target GaudiTestingAlg
GaudiTestingAlg_OBJECTS = \
"CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o"

# External object files for target GaudiTestingAlg
GaudiTestingAlg_EXTERNAL_OBJECTS =

GaudiTestingAlg/libGaudiTestingAlg.so: GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/src/TestAlg.cpp.o
GaudiTestingAlg/libGaudiTestingAlg.so: GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/build.make
GaudiTestingAlg/libGaudiTestingAlg.so: Logger/libLogger.so
GaudiTestingAlg/libGaudiTestingAlg.so: Generators/IO/libHepMCIO.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/gaudi/p7/install/lib/libP7.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/gaudi/v36r9/lib/libGaudiKernel.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/gaudi/v36r9/lib/libGaudiPluginService.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/libboost_filesystem.so.1.77.0
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/libboost_atomic.so.1.77.0
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/libboost_thread.so.1.77.0
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/libboost_regex.so.1.77.0
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/Boost/1.77.0/x86_64-centos7-gcc11-opt/lib/libboost_system.so.1.77.0
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/tbb/2020-U2/x86_64-centos7-gcc11-opt/lib/libtbb.so.2
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/fmt/7.1.3/x86_64-centos7-gcc11-opt/lib64/libfmt.so.7.1.3
GaudiTestingAlg/libGaudiTestingAlg.so: /usr/lib64/librt.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/HepMC3/hepmc3-install/lib64/libHepMC3rootIO.so.3
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/HepMC3/hepmc3-install/lib64/libHepMC3.so.4
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libTree.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libMathCore.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libImt.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libMultiProc.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libNet.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libRIO.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libThread.so
GaudiTestingAlg/libGaudiTestingAlg.so: /cvmfs/nica.jinr.ru/spd/external/ROOT/6.24.06/x86_64-centos7-gcc11-opt/lib/libCore.so
GaudiTestingAlg/libGaudiTestingAlg.so: GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module libGaudiTestingAlg.so"
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GaudiTestingAlg.dir/link.txt --verbose=$(VERBOSE)
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && /cvmfs/nica.jinr.ru/spd/external/CMake/3.20.0/x86_64-centos7-gcc11-opt/bin/cmake -E create_symlink /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg/libGaudiTestingAlg.so /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/.plugins/libGaudiTestingAlg.so
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && ../run /cvmfs/nica.jinr.ru/spd/gaudi/v36r9/bin/listcomponents --output GaudiTestingAlg.components libGaudiTestingAlg.so
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && ../run /cvmfs/nica.jinr.ru/spd/gaudi/v36r9/bin/genconf --configurable-module=GaudiKernel.Proxy --configurable-default-name=Configurable.DefaultName --configurable-algorithm=ConfigurableAlgorithm --configurable-algtool=ConfigurableAlgTool --configurable-auditor=ConfigurableAuditor --configurable-service=ConfigurableService -o genConfDir/GaudiTestingAlg -p GaudiTestingAlg -i /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg/libGaudiTestingAlg.so

# Rule to build all files generated by this target.
GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/build: GaudiTestingAlg/libGaudiTestingAlg.so
.PHONY : GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/build

GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/clean:
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg && $(CMAKE_COMMAND) -P CMakeFiles/GaudiTestingAlg.dir/cmake_clean.cmake
.PHONY : GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/clean

GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/depend:
	cd /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cvmfs/nica.jinr.ru/spd/gaudi/sampo /cvmfs/nica.jinr.ru/spd/gaudi/sampo/GaudiTestingAlg /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg /cvmfs/nica.jinr.ru/spd/gaudi/sampo/build/GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : GaudiTestingAlg/CMakeFiles/GaudiTestingAlg.dir/depend

