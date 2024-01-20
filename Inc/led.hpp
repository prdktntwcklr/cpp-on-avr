#pragma once

class Led
{
  public:
    Led() = default;                      // default constructor
    Led(const Led &) = delete;            // no copies
    Led &operator=(const Led &) = delete; // no self-assignments

    void init() const;
    void turn_on() const;
    void turn_off() const;
    void toggle() const;
    bool is_on() const;
    bool is_off() const;
};
