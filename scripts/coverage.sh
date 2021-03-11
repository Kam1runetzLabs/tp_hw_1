#!/usr/bin/env bash

set -e
export GTEST_COLOR=1
export CTEST_OUTPUT_ON_FAILURE=true

CMAKE_CONFIG_OPTS="-DCMAKE_BUILD_TYPE=Debug"
CMAKE_TOOLCHAIN_OPTS="-DCMAKE_TOOLCHAIN_FILE='$(pwd)/tools/polly/gcc-pic.cmake'"
CMAKE_OPTS="$CMAKE_CONFIG_OPTS $CMAKE_TOOLCHAIN_OPTS"

# todo fix cover
# todo html cover report
cmake -H. -B_builds -DBUILD_COVERAGE=ON "$CMAKE_OPTS"
cmake --build _builds
cmake --build _builds --target test
gcovr -r .
