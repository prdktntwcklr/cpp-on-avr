add_executable(${EXECUTABLE} led.cpp low_power.cpp main.cpp superloop.cpp timer.cpp)

target_include_directories(${EXECUTABLE} PUBLIC ${PROJECT_SOURCE_DIR}/Inc)

set_target_properties(${EXECUTABLE} PROPERTIES OUTPUT_NAME ${EXECUTABLE}.elf)

add_custom_target(size ALL ${AVR_SIZE} --format=avr --mcu=${AVR_MCU} ${EXECUTABLE}.elf)
add_custom_target(hex ALL ${AVR_OBJCOPY} -j .text -j .data -O ihex ${EXECUTABLE}.elf ${EXECUTABLE}.hex)

add_custom_target(erase COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -e)
add_custom_target(upload COMMAND ${AVR_DUDE} -p ${AVR_PARTNO} -P ${PORT_NUMBER} -c ${AVR_PROGRAMMER} -U flash:w:${EXECUTABLE}.hex)