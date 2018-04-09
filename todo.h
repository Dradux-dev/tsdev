#ifndef TSDEV_TODO_H
#define TSDEV_TODO_H

#ifdef DEBUG
# include <iostream>
#endif

namespace tsdev
{
    inline void PrintTodo(const char* Message, const char* Filename, int LineNumber)
    {
        std::cout << "ToDo: " << Message
                  << " [" << Filename << ":" << LineNumber << "]"
                  << std::endl;
    }
}

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
