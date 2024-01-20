cmake_minimum_required(VERSION 3.20)

# set name of executable
set(EXECUTABLE app)

project(CppOnAvr VERSION 0.1.0 DESCRIPTION "C++ on AVR" LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 14 CACHE STRING "The C++ standard to use")
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Src Bin)
add_subdirectory(Tests)
