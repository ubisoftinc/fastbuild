// Time.cpp
//------------------------------------------------------------------------------

// Includes
//------------------------------------------------------------------------------
#include "Time.h"
#include "Core/Env/Assert.h"

// system
#if defined( __WINDOWS__ )
    #include "Core/Env/WindowsHeader.h"
#endif
#if defined( __APPLE__ ) || defined( __LINUX__ )
    #include <sys/time.h>
#endif

// GetCurrentFileTime
//------------------------------------------------------------------------------
uint64_t Time::GetCurrentFileTime()
{
    #if defined( __WINDOWS__ )
        SYSTEMTIME st;
        FILETIME ft;
        GetSystemTime( &st );
        if ( SystemTimeToFileTime( &st, &ft ) == FALSE )
        {
            ASSERT(false); // Should never fail
            return 0;
        }
        const uint64_t fileTimeNow = ( (uint64_t)ft.dwLowDateTime | ( (uint64_t)ft.dwHighDateTime << 32 ) );
        return fileTimeNow;
    #elif defined( __APPLE__ ) || defined( __LINUX__ )
        struct timeval currentTime;
        VERIFY( gettimeofday( &currentTime, nullptr )== 0 );
        const uint64_t fileTimeNow = ( (uint64_t)currentTime.tv_sec * 1000000000ULL ) + ( (uint64_t)currentTime.tv_usec * 1000 );
        return fileTimeNow;
    #else
        #error Unknown platform
    #endif
}
//------------------------------------------------------------------------------
uint64_t Time::FileTimeToSeconds(uint64_t _filetime)
{
    #if defined( __WINDOWS__ )
        return _filetime / 10000000U;
    #else
        #error Unknown platform
    #endif
}
//------------------------------------------------------------------------------
