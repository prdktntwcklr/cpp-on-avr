#include "led.hpp"

#ifndef TEST
#include "avr/io.h"
#else
#include "testable_mcu_registers.h"
#endif

#define LED_DDR  (DDRD)
#define LED_PORT (PORTD)
#define LED_PIN  (3U)

/**
 * @brief Initializes the LED and defaults to off.
 */
void Led::init() const
{
    /* configure LED pin as output */
    LED_DDR |= (1 << LED_PIN);
    this->turn_off();
}

/**
 * @brief Turns the LED on.
 */
void Led::turn_on() const
{
    LED_PORT |= (1 << LED_PIN);
}

/**
 * @brief Turns the LED off.
 */
void Led::turn_off() const
{
    LED_PORT &= ~(1 << LED_PIN);
}

/**
 * @brief Toggles the LED.
 */
void Led::toggle() const
{
    LED_PORT ^= (1 << LED_PIN);
}

/**
 * @brief Returns TRUE if the LED is on.
 */
bool Led::is_on() const
{
    return ((LED_PORT) & (1 << LED_PIN));
}

/**
 * @brief Returns TRUE if the LED is off.
 */
bool Led::is_off() const
{
    return !(this->is_on());
}
