#include <iostream>

#ifndef DEBUG
# define DEBUG 1
#endif

#ifndef TODO_USE_ERROR
# define TODO_USE_ERROR_xxx 1
#endif

#include <tsdev/todo.h>

int main(int, char**)
{
  std::cout << "Demo for a simple Todo mark" << std::endl;

  const float Radius = 3.0f;
  std::cout << "Calculating the area of a circle with a radius of 3" << std::endl;

  TODO("Replace square formula by circle formula");
  float Space = Radius * Radius;

  std::cout << "Area: " << Space << std::endl;

  return 0;
}
