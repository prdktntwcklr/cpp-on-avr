#include "superloop.hpp"
#include "led.hpp"
#include "timer.hpp"

static constexpr uint16_t TOGGLE_INTERVAL_IN_MS{1000U};

static Led led{};
static Timer timer{};

/**
 * @brief Initializes the relevant peripherals for the superloop.
 *
 * @note  See the following for a discussion why this should not be done inside
          the constructor:
          https://www.reddit.com/r/embedded/comments/q3orsi/embedded_c_question_regarding_constructors/?rdt=45370
 */
void Superloop::init() const
{
    led.init();
    timer.init();
}

/**
 * @brief Runs the superloop. Should always return true to keep loop running.
 */
bool Superloop::run()
{
    if(timer.deadline_reached(deadline))
    {
        deadline += TOGGLE_INTERVAL_IN_MS;

        led.toggle();
    }

    return true;
}
