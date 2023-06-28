#!/bin/bash
export CPATH=/opt/homebrew/include
export LIBRARY_PATH=/opt/homebrew/lib
cmake -DCMAKE_BUILD_TYPE=Debug .
cmake --build . -- -j4
./build/GameOfThrive