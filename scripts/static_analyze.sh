#!/usr/bin/env bash

CXX_CPPCHECK_OPTIONS="--language=c --std=c11 --verbose "
C_CPPCHECK_OPTIONS="--language=c++ --std=c++11 --verbose "

files=`find . -name "*.c" -or -name "*.h" -or -name "*.cpp" -or -name "*hpp" | grep -v "./tools/*"`
for file in $files
do
echo 
echo "Checking $(basename -- $file) ..."
if [ "*pp"=="${file##*.}" ]; then
    cppcheck $CXX_CPPCHECK_OPTIONS $file
else
    cppcheck $C_CPPCHECK_OPTIONS $file
fi
done
