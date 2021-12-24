#include <iostream>
#include "my_math.h"
#include "say_hello.h"

int main(int argv, char **argc)
{
  example::sayHello("World!");
  std::cout << "2 + 3 = " << example::add(2, 3) << "\n";
  return 0;
}
