#pragma once

#include "stdint.h"

#ifndef TEST

#include "avr/io.h"

#else

#include "testable_mcu_registers.hpp"

#endif

namespace PinMap
{
static constexpr auto led_pin = uint8_t{3};
static volatile constexpr uint8_t *led_ddr{&DDRD};
static volatile constexpr uint8_t *led_port{&PORTD};
} // namespace PinMap
