/*
 * This example demonstrates the usage of the TODO macro.
 *
 * When the expansion of the TODO macro is executed, it will
 * generate a message on the STDOUT, that contains the TODO
 * description, the source filename and the line number.
 *
 * Steps:
 *   1. Define DEBUG, if not already defined
 *   2. Include "todo.h"
 *   3. Use TODO macro, wherever needed
 *
 * Author: Tarek Schwarzinger <tarek.schwarzinger@googlemail.com>
 */



#include <iostream>

/*
 * Enable DEBUG mode, so that everything will work.
 */
#ifndef DEBUG
# define DEBUG 1
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
   * Generates the todo message on execution. In it's normal
   * behavior this will generate a message on the STDOUT.
   * Alternatively the TODO macro can be configured to generate
   * a break point (TODO_USE_BREAK). This is demonstrated in
   * "002-todo-break". Another possible behavior is generating
   * compiler errors (TODO_USE_ERROR). This is demonstrated in
   * "003-todo-error".
   *
   * If the software is compiled in a non DEBUG version, the
   * expansion of the TODO macro will generate an empty line.
   */
  TODO("Replace square formula by circle formula");
  float Space = Radius * Radius;

  std::cout << "Area: " << Space << std::endl;

  return 0;
}
