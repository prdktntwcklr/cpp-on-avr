#!/usr/bin/env bash

# Script to run a pristine build from inside the Docker container

rm -rf Build
cmake -DCMAKE_TOOLCHAIN_FILE="avr.cmake" -B Build/Avr
cmake --build Build/Avr --target app size hex
