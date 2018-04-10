#ifndef TSDEV_TODO_H
#define TSDEV_TODO_H

#ifdef DEBUG
# include <iostream>
#endif

namespace tsdev
{
  /*
   * Function that prints the todo message on the STDOUT.
   *
   * DEBUG: Function that prints the message.
   * RELEASE: Empty function.
   */
  #ifdef DEBUG
  inline void PrintTodo(const char* Message, const char* Filename, int LineNumber)
  {
      std::cout << "ToDo: " << Message
                << " [" << Filename << ":" << LineNumber << "]"
                << std::endl;
  }
  #else
  inline void PrintTodo(const char*, const char*, int) {}
  #endif
}

/*
 * Generates the different versions of the todo macro.
 *
 * DEBUG:
 *  NORMAL: Prints the ToDo message on the STDOUT
 *  BREAK: Generates a breakpoint at the ToDo macro expansion
 *  ERROR: Generates a compiler error at the ToDo macro expansion
 *
 * RELEASE: Empty macro, so that it generates not extra costs.
 */
#ifdef DEBUG
#if !defined(TODO_USE_BREAK) && !defined(TODO_USE_ERROR)
# define TODO(msg) do { tsdev::PrintTodo(msg, __FILE__, __LINE__); } while(false)
#elif defined(TODO_USE_BREAK)
# include "break.h"
# define TODO(msg) do { tsdev:: PrintTodo(msg, __FILE__, __LINE__); tsdev::DebugBreak(); } while (false)
#elif defined(TODO_USE_ERROR)
# define TODO(msg) do { xxx } while (false)
#endif // TODO w/o Break, Error
#else
# define TODO(msg) do {} while(false)
#endif // DEBUG

#endif // TSDEV_TODO_H
