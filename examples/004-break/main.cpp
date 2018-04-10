#include <iostream>

#ifndef DEBUG
# define DEBUG 1
#endif

#ifndef BREAK_ERROR
# define BREAK_ERROR_xxx 1
#endif

#include <tsdev/break.h>

int main(int, char**)
{
  std::cout << "Break demo for TsDev library" << std::endl;

  for (int i = 0; i < 7; ++i)
  {
    std::cout << "i=" << i << std::endl;
    std::cout << ">=5: " << ((i >= 5) ? "True" : "False") << std::endl;

    if (i >= 5)
    {
      std::cout << "Triggering breakpoint" << std::endl;
      tsdev::DebugBreak();
    }
  }

  return 0;
}
