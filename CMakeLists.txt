cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)

project(
    CppOnAvr
    VERSION 0.1.0
    DESCRIPTION "C++ on AVR"
    LANGUAGES CXX)

add_subdirectory(Src Bin)
