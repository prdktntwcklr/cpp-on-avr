#include "superloop.hpp"
#include "led.hpp"
#include "pinmap.hpp"
#include "timer.hpp"

namespace
{
constexpr auto TOGGLE_INTERVAL_IN_MS = uint16_t{1'000};

Led led{PinMap::led_pin, PinMap::led_ddr, PinMap::led_port};
Timer timer{};
} // namespace

static_assert(TOGGLE_INTERVAL_IN_MS > 0,
              "toggle interval must be greater than 0!");

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
