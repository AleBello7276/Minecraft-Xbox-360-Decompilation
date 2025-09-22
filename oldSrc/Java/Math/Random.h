#pragma once 
#include "stdint.h"

class Random
{
private:
    uint64_t state; // current seed
    bool haveNextNextGaussian;
    double nextNextGaussian;


    static const uint64_t multiplier = 0x5DEECE66DULL;
    static const uint64_t addend = 0xBULL;
    static const uint64_t mask = 0xFFFFFFFFFFFF /*(1L << 48) - 1*/;

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


    float nextFloat()
    {
        uint64_t uVar1 = state * multiplier + addend & mask;
        state = uVar1;
        return static_cast<float>(((uVar1 >> 0x18))  * 5.9604645e-08f);
    }

    double nextDouble()
    {
        // 1 next
        uint64_t uVar1 = state * multiplier + addend & mask;
        state = uVar1;
        uint64_t a = uVar1 >> 0x16;
        // 2 next
        uint64_t uVar2 = state * multiplier + addend & mask;
        state = uVar2;
        uint64_t b = uVar2 >> 0x15;

        return static_cast<double>((static_cast<uint64_t>(a) << 27) + static_cast<uint64_t>(b)) / static_cast<double>(1ull << 53);

    }

    

    // https://github.com/openjdk-mirror/jdk7u-jdk/blob/master/src/share/classes/java/util/Random.java#L496
    double nextGaussian()
    {
        if(haveNextNextGaussian)
        {
            haveNextNextGaussian = false;
            return nextNextGaussian;
        } 
        else 
        {
            double v1, v2, s;
            do {
                v1 = 2 * nextDouble() - 1; 
                v2 = 2 * nextDouble() - 1; 

                s = v1 * v1 + v2 * v2;
            } while (s >= 1 || s == 0);
            double multiplier = sqrt(-2 * log(s)/s);
            nextNextGaussian = v2 * multiplier;
            haveNextNextGaussian = true;
            return v1 * multiplier;
            
        }
    }

    
    

};