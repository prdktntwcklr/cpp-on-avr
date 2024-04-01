#include "main.hpp"
#include "low_power.hpp"
#include "superloop.hpp"

namespace
{
Superloop superloop{};
LowPower lowpower{};
} // namespace

#ifndef TEST
int main()
#else
int testable_main()
#endif
{
    superloop.init();
    lowpower.init();

    while(superloop.run())
    {
        lowpower.enter();
    }

    // this line is never reached
    return 0;
}
