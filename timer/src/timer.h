#pragma once

#include <iostream>

namespace Timer
{
  class Rate
  {
  public:
    Rate(double period);

    void setPeriod(double s);
    void sleep();

  private:
    struct timespec next_time;
    double _period;
  };

  class Meter
  {
  public:
    void begin();
    double end(double *time);

  private:
    struct timespec t0, t1;
  };

} // namespace Timer
