# CMakeList.txt: archivo del proyecto de CMake de nivel superior, establezca la configuración global
# e incluya los subproyectos aquí.
#
cmake_minimum_required (VERSION 3.8)

project ("EasyDump")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_SHARED_LIBS "Build EasyDump as a shared library." ON)
option(BUILD_STATIC_LIBS "Build EasyDump as a static library." ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

# Incluya los subproyectos.
add_subdirectory("EasyDump")

add_executable(test-easy main.cpp)
target_link_libraries(test-easy EasyDump)
