/* led.c */

#include "led.h"

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
extern void led_init()
{
    /* configure LED pin as output */
    LED_DDR |= (1 << LED_PIN);
    led_turn_off();
}

/**
 * @brief Turns the LED on.
 */
extern void led_turn_on()
{
    LED_PORT |= (1 << LED_PIN);
}

/**
 * @brief Turns the LED off.
 */
extern void led_turn_off()
{
    LED_PORT &= ~(1 << LED_PIN);
}

/**
 * @brief Toggles the LED.
 */
extern void led_toggle()
{
    LED_PORT ^= (1 << LED_PIN);
}

/**
 * @brief Returns TRUE if the LED is on.
 */
extern bool led_is_on()
{
    return ((LED_PORT) & (1 << LED_PIN));
}

/**
 * @brief Returns TRUE if the LED is off.
 */
extern bool led_is_off()
{
    return !(led_is_on());
}
