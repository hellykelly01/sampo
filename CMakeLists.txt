cmake_minimum_required(VERSION 3.16...3.21)

project(sampo)


list(PREPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/modules")
include(cmake/sampoDependencies.cmake)

add_subdirectory(Examples)
add_subdirectory(Generators)
add_subdirectory(DetectorDescription)
add_subdirectory(Logger)

add_subdirectory(GaudiTestingAlg)

add_executable(sampo main.cpp)

target_link_libraries(sampo Gaudi::GaudiKernel)

