#ifndef TSDEV_CHECK_H
#define TSDEV_CHECK_H

#include "break.h"

/*
 * If the condition fails, the macro will trigger a breakpoint (DEBUG).
 *
 * DEBUG: Triggers a breakpoint on condition failure.
 * RELEASE: Generates an empty macro.
 */
#ifdef DEBUG
# define CHECK(condition) do { if(!condition) { tsdev::DebugBreak(); } } while(false)
#else
# define CHECK(condition) do {} while(false)
#endif // DEBUG

#endif // TSDEV_CHECK_H
