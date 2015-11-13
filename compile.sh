#!/bin/bash

echo "-- Setting up Environment."
set -e

if [ ! -d "build" ]; then
    mkdir build
fi
if [ -d "dbg" ]; then
    rm -rd dbg
fi
if [ -d "tmp" ]; then
    rm -rd tmp
fi
mkdir dbg
mkdir tmp

echo "-- Compiling."
cd build
cmake .. $@
make $MAKEOPTS 

echo "-- Executing Tests."
cd ../
build/src/stat-test
