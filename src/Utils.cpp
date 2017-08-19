#include <iostream>

#include "app/Utils.hpp"

int Utils::randEven(int max)
{
  int v = std::rand() % max;

  if (v == 0)
  {
    v = 2;
  }
  else if ((v % 2) != 0)
  {
    v++;
  }

  return v;
}
