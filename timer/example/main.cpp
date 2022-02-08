#include <iostream>
#include <string.h>
#include <pthread.h>
#include "timer.h"

pthread_t thread_app;

void *app_thread(void *arg)
{
  Timer::Rate loopRate(0.01);
  Timer::Meter timeMater;
  double runTime = 0;
  while (1)
  {
    timeMater.begin();
    loopRate.sleep();
    runTime = timeMater.end(NULL);
    printf("Run time: %f\r", runTime);
  }
  return 0;
}

int main(int argv, char **argc)
{

  int ret = 0;
  ret = pthread_create(&thread_app, NULL, app_thread, NULL);
  if (ret != 0)
  {
    printf("Create app_thread failed! ret %s\n", strerror(ret));
    return -2;
  }
  Timer::Rate loopRate(0.1);
  while (1)
  {
    loopRate.sleep();
  }
  pthread_join(thread_app, NULL);
  return 0;
}
