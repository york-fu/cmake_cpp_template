#include "linux_timer.h"

namespace Timer
{
  Rate::Rate(double period) : _period(period)
  {
    clock_gettime(CLOCK_MONOTONIC, &next_time);
  }

  Rate::~Rate()
  {
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
} // namespace Timer
