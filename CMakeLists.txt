cmake_minimum_required(VERSION 3.20)

# set name of executable
set(EXECUTABLE app)

# export compile commands for clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

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

add_executable(${EXECUTABLE} Src/main.cpp)
target_sources(${EXECUTABLE} PRIVATE Src/led.cpp)
target_sources(${EXECUTABLE} PRIVATE Src/low_power.cpp)
target_sources(${EXECUTABLE} PRIVATE Src/superloop.cpp)
target_sources(${EXECUTABLE} PRIVATE Src/timer.cpp)

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/Inc)

set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${EXECUTABLE}.elf)

add_custom_target(size ALL ${AVR_SIZE} --format=avr --mcu=${AVR_MCU} ${EXECUTABLE}.elf)
add_custom_target(hex ALL ${AVR_OBJCOPY} -j .text -j .data -O ihex ${EXECUTABLE}.elf ${EXECUTABLE}.hex)

add_custom_target(erase COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -e)
add_custom_target(upload COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -U flash:w:${EXECUTABLE}.hex)

add_subdirectory(Tests)
