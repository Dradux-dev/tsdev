#ifndef TSDEV_BREAK_H
#define TSDEV_BREAK_H

#ifdef WIN32
# include <windows.h>
#endif

namespace tsdev
{
    inline void DebugBreak()
    {
        #ifdef WIN32
            ::DebugBreak();
        #endif
    }
}

#endif
