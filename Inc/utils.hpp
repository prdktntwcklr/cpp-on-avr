#pragma once

class Noncopyable
{
  protected:
    Noncopyable() = default;
    ~Noncopyable() = default;

  private:
    Noncopyable(const Noncopyable &) = delete;            // no copies
    Noncopyable &operator=(const Noncopyable &) = delete; // no self assignments
    Noncopyable(Noncopyable &&) = delete;                 // no move constructor
    Noncopyable &operator=(Noncopyable &&) = delete;      // no move assignment
};
