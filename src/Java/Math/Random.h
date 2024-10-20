#pragma once 
#include "stdint.h"

class Random
{
private:
    uint64_t state; // current seed
    bool haveNextNextGaussian;

    static const uint64_t multiplier = 0x5DEECE66DULL;
    static const uint64_t addend = 0xBULL;
    static const uint64_t mask = (1L << 48) - 1;

public:
    Random(uint64_t seed) 
    {
        setSeed(seed);
    }

    void setSeed(uint64_t newStateSeed)
    {
        haveNextNextGaussian = false;
        state = (newStateSeed ^ multiplier) & mask; // cap the seed to lower 48 bits
    }

    int32_t nextInt()
    {
        //next(32);
        uint64_t uVar1 = state * multiplier + addend & mask;
        state = uVar1;
        return static_cast<int32_t>(uVar1 >> 16);
    }

    // nextInt with bounds
    uint32_t nextInt(int32_t n)
    {
        uint32_t bits, val;

        if ((-n & n) == n) // n power of 2
        {
            uint64_t uVar4 = state * multiplier + addend & mask;
            state = uVar4;
            return static_cast<uint32_t>(uVar4 >> 0x11) * (n >>= 0x1f); 
        }

        do
        {
            uint64_t uVar1 = state * multiplier + addend & mask;
            state = uVar1;
            bits = static_cast<uint32_t>(uVar1 >> 0x11);
            val = bits % n; // https://github.com/openjdk-mirror/jdk7u-jdk/blob/master/src/share/classes/java/util/Random.java#L308
        } while ((bits - val) + (n-1) < 0);
        return static_cast<uint32_t>(val);
    }

    long nextLong()
    {
        // TODO
        return 0;
    }
};