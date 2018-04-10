#ifndef TSDEV_BREAK_H
#define TSDEV_BREAK_H

#ifdef WIN32
# include <windows.h>
#endif

namespace tsdev
{
  /*
   * Generates a breakpoint.
   *
   * DEBUG: Generates the breakpoint.
   * RELEASE:
   *  NORMAL: Replaces the breakpoint generation with an empty function.
   *  ERROR: Replaces the breakpoint generation with nothing to generate compiler errors.
   */
  #ifdef DEBUG
  inline void DebugBreak()
  {
      #ifdef WIN32
          ::DebugBreak();
      #endif
  }
  #else
  # ifndef BREAK_ERROR
  inline void DebugBreak() {}
  # endif // BREAK_ERROR
  #endif // DEBUG
}

#endif // TSDEV_BREAK_H
