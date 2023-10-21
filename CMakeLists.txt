cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE toolchain.cmake)

project(
    CppOnAvr
    VERSION 0.1.0
    DESCRIPTION "C++ on AVR"
    LANGUAGES CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Src Bin)
