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
 *   2. Define TODO_USE_ERROR, to enable compiler error generation
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
 * Define TODO_USE_BREAK, to enable compiler error generation
 *
 * Note: To get the compiler error demonstrated, you have to
 *       remove the "_xxx". This needs to be added, to get the
 *       full project compiled, but disturbs this demo.
 */
#ifndef TODO_USE_ERROR
# define TODO_USE_ERROR_xxx 1
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
   * Generates a compiler error on the TODO macro expansion. This
   * is defined by the error behavior with TODO_USE_ERROR. The
   * compiler error generation can be disable, by not defining
   * TODO_USE_ERROR. This sets the TODO macro to it's normal
   * behavior. This is demonstrated in "001-todo". Alternatively the
   * TODO macro can trigger a breakpoint instead of generating a
   * compiler error, by defining TODO_USE_BREAK. This is shown in
   * the demonstration "002-todo-break".
   *
   * If the software is compiled in a non DEBUG version, the
   * expansion of the TODO macro will generate an empty line.
   */
  TODO("Replace square formula by circle formula");
  float Space = Radius * Radius;

  std::cout << "Area: " << Space << std::endl;

  return 0;
}
