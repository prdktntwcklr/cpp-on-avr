#pragma once

class LowPower
{
  public:
    LowPower() = default;                           // default constructor
    LowPower(const LowPower &) = delete;            // no copies
    LowPower &operator=(const LowPower &) = delete; // no self-assignments

    void init() const;
    void enter() const;
};
