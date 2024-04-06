#include "led.hpp"

/**
 * @brief Constructor definition.
 */
Led::Led(pin_type pin, ddr_type *ddr, port_type *port)
    : pin(pin), ddr(ddr), port(port)
{
}

/**
 * @brief Initializes the LED and defaults to off.
 */
void Led::init()
{
    // turn off LED and configure pin as output
    turn_off();
    *ddr |= (1U << pin);
}

/**
 * @brief Turns the LED on.
 */
void Led::turn_on()
{
    *port |= (1U << pin);

    led_on = true;
}

/**
 * @brief Turns the LED off.
 */
void Led::turn_off()
{
    *port &= ~(1U << pin);

    led_on = false;
}

/**
 * @brief Toggles the LED.
 */
void Led::toggle()
{
    *port ^= (1U << pin);

    led_on = (!led_on);
}

/**
 * @brief Returns true if the LED is on.
 */
bool Led::is_on() const
{
    return led_on;
}

/**
 * @brief Returns true if the LED is off.
 */
bool Led::is_off() const
{
    return !(is_on());
}
