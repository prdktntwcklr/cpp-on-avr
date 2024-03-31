#include "led.hpp"

/**
 * @brief Constructor definition.
 */
Led::Led(uint8_t led_pin, volatile uint8_t *led_ddr, volatile uint8_t *led_port)
    : pin(led_pin), ddr(led_ddr), port(led_port)
{
}

/**
 * @brief Initializes the LED and defaults to off.
 */
void Led::init() const
{
    /* configure LED pin as output */
    *ddr |= (1 << pin);
    this->turn_off();
}

/**
 * @brief Turns the LED on.
 */
void Led::turn_on() const
{
    *port |= (1 << pin);
}

/**
 * @brief Turns the LED off.
 */
void Led::turn_off() const
{
    *port &= ~(1 << pin);
}

/**
 * @brief Toggles the LED.
 */
void Led::toggle() const
{
    *port ^= (1 << pin);
}

/**
 * @brief Returns TRUE if the LED is on.
 */
bool Led::is_on() const
{
    return ((*port) & (1 << pin));
}

/**
 * @brief Returns TRUE if the LED is off.
 */
bool Led::is_off() const
{
    return !(this->is_on());
}
