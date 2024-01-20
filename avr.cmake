##########################################################################
# Toolchain file for AVR ATmega168A
##########################################################################

# define executables in use
find_program(AVR_CC avr-gcc REQUIRED)
find_program(AVR_CXX avr-g++ REQUIRED)
find_program(AVR_OBJCOPY avr-objcopy REQUIRED)
find_program(AVR_SIZE avr-size REQUIRED)
find_program(AVR_DUDE avrdude REQUIRED)

# define mandatory variables
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_C_COMPILER ${AVR_CC})
set(CMAKE_CXX_COMPILER ${AVR_CXX})

# set mcu details
set(AVR_MCU atmega168a)
set(AVR_PARTNO m168)
set(AVR_PROGRAMMER avrispv2)
set(F_CPU "1000000UL")

# set serial port, works under Windows only
set(PORT_NUMBER COM6)

# set linker flags
set(CMAKE_EXE_LINKER_FLAGS -mmcu=${AVR_MCU})

# set compile options
add_compile_options(
    -Werror
    -Wall
    -Wextra
    -pedantic
    -g
    -Os
    -mmcu=${AVR_MCU}
    -DF_CPU=${F_CPU})
