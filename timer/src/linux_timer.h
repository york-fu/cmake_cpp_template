#pragma once

#include <iostream>

namespace Timer
{
  class Rate
  {
  public:
    Rate(double period);
    ~Rate();

    void setPeriod(double s);
    void sleep();

  private:
    struct timespec next_time;
    double _period;
  };

} // namespace Timer
