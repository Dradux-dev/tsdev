#ifndef TSDEV_CHECK_H
#define TSDEV_CHECK_H

#include "break.h"

#ifdef DEBUG
# define CHECK(condition) do { if(!condition) { tsdev::DebugBreak(); } } while(false)
#else
# define CHECK(condition)
#endif // DEBUG

#endif // TSDEV_CHECK_H
