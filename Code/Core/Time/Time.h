// Time.h
//------------------------------------------------------------------------------
#pragma once

// Includes
//------------------------------------------------------------------------------
#include "Core/Env/Types.h"

// Time
//------------------------------------------------------------------------------
class Time
{
public:
    static uint64_t GetCurrentFileTime();
    static uint64_t FileTimeToSeconds(uint64_t _filetime);
};

//------------------------------------------------------------------------------
