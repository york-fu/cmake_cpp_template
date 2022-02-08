#include "timer.h"

namespace Timer
{
  Rate::Rate(double period) : _period(period)
  {
    clock_gettime(CLOCK_MONOTONIC, &next_time);
  }

  void Rate::setPeriod(double s)
  {
    _period = s;
  }

  void Rate::sleep()
  {
    next_time.tv_sec += (next_time.tv_nsec + _period * 1e9) / 1e9;
    next_time.tv_nsec = (int)(next_time.tv_nsec + _period * 1e9) % (int)1e9;
    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &next_time, NULL);
  }

  void Meter::begin()
  {
    clock_gettime(CLOCK_MONOTONIC, &t0);
  }

  double Meter::end(double *time)
  {
    clock_gettime(CLOCK_MONOTONIC, &t1);
    double t = (t1.tv_sec + t1.tv_nsec * 1e-9) - (t0.tv_sec + t0.tv_nsec * 1e-9);
    if (time != NULL)
    {
      *time = t;
    }
    return t;
  }
} // namespace Timer
