cmake_minimum_required(VERSION 3.4)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_TESTS "Build tests" ON)
option(BUILD_COVERAGE "Build coverage" OFF)
option(CMAKE_BUILD_DEBUG "Build debug" OFF)

#include("tools/gate/cmake/HunterGate.cmake")
#
#HunterGate(
#        URL "https://github.com/cpp-pm/hunter/archive/v0.23.278.tar.gz"
#        SHA1 "35fa55bc1dfcf9f4d7264f8bb26cd1759ce1ae07"
#)

project(first_homework VERSION 0.1.0)

string(APPEND CMAKE_C_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_C_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_C_FLAGS " -Wshadow")
string(APPEND CMAKE_CXX_FLAGS " -pedantic -Werror -Wall -Wextra")
string(APPEND CMAKE_CXX_FLAGS " -Wno-unused-command-line-argument")
string(APPEND CMAKE_CXX_FLAGS " -Wshadow -Wnon-virtual-dtor")

add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(tests)
    enable_testing()
endif()

if (BUILD_COVERAGE)
    string(APPEND CMAKE_C_FLAGS " --coverage")
    string(APPEND CMAKE_CXX_FLAGS " --coverage")
    string(APPEND CMAKE_EXE_LINKER_FLAGS " --coverage")
    string(APPEND CMAKE_MODULE_LINKER_FLAGS " --coverage")
    string(APPEND CMAKE_SHARED_LINKER_FLAGS " --coverage")
endif()

if (CMAKE_BUILD_DEBUG)
    string(APPEND CMAKE_C_FLAGS " -g")
    string(APPEND CMAKE_CXX_FLAGS " -g")
endif ()
