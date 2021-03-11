#!/usr/bin/env bash

CXX_CPPCHECK_OPTIONS="--language=c --std=c11 --verbose "
C_CPPCHECK_OPTIONS="--language=c++ --std=c++11 --verbose "

cppcheck $C_CPPCHECK_OPTIONS --xml --xml-version=2 ./src 2>report-src.xml
cppcheck-htmlreport --file=report-src.xml --report-dir=report-src

cppcheck $CXX_CPPCHECK_OPTIONS --xml --xml-version=2 ./tests 2>report-tests.xml
cppcheck-htmlreport --file=report-tests.xml --report-dir=report-tests
