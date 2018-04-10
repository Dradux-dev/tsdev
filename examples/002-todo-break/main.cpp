/*
 * This example demonstrates the usage of the TODO macro.
 *
 * When the expansion of the TODO macro is executed, it will
 * generate a message on the STDOUT, that contains the TODO
 * description, the source filename and the line number.
 * Additionally it generates a breakpoint in the TODO macro
 * execution.
 *
 * Steps:
 *   1. Define DEBUG, if not already defined
 *   2. Define TODO_USE_BREAK, to enable breakpoint generation
 *   3. Include "todo.h"
 *   4. Use TODO macro, wherever needed
 *
 * Author: Tarek Schwarzinger <tarek.schwarzinger@googlemail.com>
 */



#include <iostream>

/*
 * Define DEBUG, to enable TODO macro expansion
 */
#ifndef DEBUG
# define DEBUG 1
#endif

/*
 * Define TODO_USE_BREAK, to enable breakpoint generation
 */
#ifndef TODO_USE_BREAK
# define TODO_USE_BREAK 1
#endif

/*
 * Include the needed header file.
 */
#include <tsdev/todo.h>

int main(int, char**)
{
  std::cout << "Demo for a simple Todo mark" << std::endl;

  const float Radius = 3.0f;
  std::cout << "Calculating the area of a circle with a radius of 3" << std::endl;

  /*
   * Generates the todo message on execution. In it's break
   * behavior this will generate a message on the STDOUT and triggers
   * a breakpoint. To disable the breakpoint generation remove the definition of
   * TODO_USE_BREAK, seen in the demonstration "001-todo".
   * Another possible behavior is generating compiler errors (TODO_USE_ERROR).
   * This is demonstrated in "003-todo-error".
   *
   * If the software is compiled in a non DEBUG version, the
   * expansion of the TODO macro will generate an empty line.
   */
  TODO("Replace square formula by circle formula");
  float Space = Radius * Radius;

  std::cout << "Area: " << Space << std::endl;

  return 0;
}
