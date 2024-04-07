#pragma once

#include "stdint.h"

#ifndef TEST

#include "avr/io.h"

#else

#include "testable_mcu_registers.hpp"

#endif

// clang-format off

namespace PinMap
{
constexpr auto led_pin = uint8_t{3};
constexpr volatile uint8_t *led_ddr(){ return &DDRD; }
constexpr volatile uint8_t *led_port() {return &PORTD; }
} // namespace PinMap

// clang-format on
