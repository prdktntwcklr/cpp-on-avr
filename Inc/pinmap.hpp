#pragma once

#include "stdint.h"

#ifndef TEST
#include "avr/io.h"
#else
#include "testable_mcu_registers.h"
#endif

namespace PinMap
{
static constexpr uint8_t led_pin{UINT8_C(3)};
static volatile constexpr uint8_t *led_ddr{&DDRD};
static volatile constexpr uint8_t *led_port{&PORTD};
} // namespace PinMap
