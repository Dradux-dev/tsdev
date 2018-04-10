/*
 * This example demonstrates the usage of the breakpoint generation.
 *
 * Whenever the function tsdev::DebugBreak() is called, it will trigger
 * a breakpoint.
 *
 * Steps:
 *   1. Define DEBUG, if not already defined
 *   2. Define BREAK_ERROR, if compiler errors generation is
 *      wished everywhere DebugBreak() is used
 *   3. Include "break.h"
 *   4. Use DebugBreak() function, wherever needed
 *
 * Author: Tarek Schwarzinger <tarek.schwarzinger@googlemail.com>
 */



#include <iostream>

/*
 * Define DEBUG, so that the breakpoint generation will work
 */
#ifndef DEBUG
# define DEBUG 1
#endif

/*
 * Define BREAK_ERROR, to enable compiler error generation.
 *
 * Note: Remove the "_xxx" to get this demonstration working. This
 *       needs to defined wrong, to get the compilation of the full
 *       project working, but it is unfavorable for the demonstration
 *       of the compiler error generation.
 */
#ifndef BREAK_ERROR
# define BREAK_ERROR_xxx 1
#endif

/*
 * Include the needed header file
 */
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

      /*
       * Triggers the breakpoint whereever needed. In DEBUG mode
       * this will really trigger the breakpoint. In a non DEBUG
       * mode compilation, the function is an empty inline
       * function, so that it won't be in the final execution, thanks
       * to compiler optimization.
       */
      tsdev::DebugBreak();
    }
  }

  return 0;
}
