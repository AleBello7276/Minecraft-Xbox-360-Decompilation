#include "Timer.h"

// 0x824d70b8
// i guess this is some sort of reimplementation that 4J did of java's System.nanoTime() using GetTickCount()
long Timer::getNanoTime()
{  
  // why * 1000000 ?! (it's based on ghidra disassembly)
    return GetTickCount() * 1000000;
}

// 0x824d70e8
// same thing as nanoTime i guess, it's some sort of reimplementation of System.currentTimeMillis()
unsigned long long Timer::currentTimeMills()
{
    SYSTEMTIME systemTime; 
    FILETIME fileTime;
    unsigned long long  fileTimeIn64;

    GetSystemTime(&systemTime); // 0x826b2f58
    SystemTimeToFileTime(&systemTime, &fileTime); // 0x822be100
    
    fileTimeIn64 = ((unsigned long long )fileTime.dwHighDateTime << 32) | fileTime.dwLowDateTime; 

    // from 100-nanosecond intervals to milliseconds i guess !?!?
    return fileTimeIn64 / 10000;
}

// 0x8224c078
Timer::Timer(float tps) : timeSyncAdjustment(1.0f), timerSpeed(1.0f), elapsedPartialTicks(0.0f)
{
    this->ticksPerSecond = tps;
    this->lastSyncSysClock = this->currentTimeMills();
    this->lastSyncHRClock = this->getNanoTime() / 1000000;
}


// 0x8224c108
void Timer::updateTimer()
{
    long startTimeMills = this->currentTimeMills();
    long deltaSysClock = startTimeMills - this->lastSyncSysClock;
    long startTimeNano = this->getNanoTime() / 1000000;  

    double var7 = (double)startTimeNano * 0.001; // double var7 = (double)var5 / 1000.0D;

    if (deltaSysClock > 1000L) 
    {
        this->lastHRTime = var7;
    } else if (deltaSysClock < 0) {
        this->lastHRTime = var7;
    } 
    else {
        this->field_28132_i = this->field_28132_i + deltaSysClock;
        if (1000 < field_28132_i) {
            double var11 = (double)this->field_28132_i / (double)(startTimeNano - this->lastSyncHRClock);
            this->timeSyncAdjustment += (var11 - this->timeSyncAdjustment) * 0.2f;
            this->lastSyncHRClock = startTimeNano;
            this->field_28132_i = 0;
        }
        if (this->field_28132_i < 0) {
          this->lastSyncHRClock = startTimeNano;
        }
     }

    this->lastSyncSysClock = startTimeMills;
    double var13 = (var7 - this->lastHRTime) * this->timeSyncAdjustment;
    this->lastHRTime = var7;

    if(var13 < 0.0f) {
		var13 = 0.0f;
	}

	if(var13 > 1.0f) {
		var13 = 1.0f;
	}

    this->elapsedPartialTicks = (float)((double)this->elapsedPartialTicks + var13 * (double)this->timerSpeed * (double)this->ticksPerSecond);
    this->elapsedTicks = (int)this->elapsedPartialTicks;
	this->elapsedPartialTicks -= (float)this->elapsedTicks;

    if (10 < this->elapsedTicks) {
      this->elapsedTicks = 10;
    }

    this->renderPartialTicks = this->elapsedPartialTicks;
}
