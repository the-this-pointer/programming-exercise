#ifndef UTIL_H
#define UTIL_H

#include <iostream>

void printContainer(const auto& container)
{
  for (const auto& v: container)
  {
    std::cout << v << " ";
  }
  std::cout << std::endl;
}

#endif //UTIL_H
