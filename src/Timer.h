#pragma once

#include <xtl.h>
#include <xboxmath.h>


class Timer {
public:
    float ticksPerSecond;
    float timerSpeed;
    int elapsedTicks;
    float renderPartialTicks;
    float elapsedPartialTicks;

    Timer(float tps);
    void updateTimer();

    unsigned long long currentTimeMills();
    long getNanoTime();

private:
    unsigned long long lastSyncSysClock;
    long lastSyncHRClock;
    long field_28132_i;
    double timeSyncAdjustment;
    double lastHRTime;
    
};

