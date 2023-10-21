#include "superloop.h"
#include "led.h"
#include "timer.h"

static constexpr uint16_t TOGGLE_INTERVAL_IN_MS {1000U};

/**
 * @brief Initializes the relevant peripherals for the superloop.
 *
 * @note  See the following for a discussion why this should not be done inside
          the constructor:
          https://www.reddit.com/r/embedded/comments/q3orsi/embedded_c_question_regarding_constructors/?rdt=45370
 */
void Superloop::init()
{
    led_init();
    timer_init();
}

/**
 * @brief Runs the superloop. Should always return true to keep loop running.
 */
bool Superloop::run()
{
    static uint16_t deadline = 0;

    if(timer_deadline_reached(deadline))
    {
        deadline += TOGGLE_INTERVAL_IN_MS;

        led_toggle();
    }

    return true;
}
