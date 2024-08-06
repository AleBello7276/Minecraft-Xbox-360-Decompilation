#pragma once
#pragma once

#include <cmath>
#include <string>

class MathHelper {
private:
    static float SIN_TABLE[65536];

public:
    static float sin(float value);
    static float cos(float value);
    static float sqrt_float(float value);
    static float sqrt_double(double value);
    static int floor_float(float value);
    static int floor_double(double value);
    static float abs(float value);
    static double abs_max(double value1, double value2);
    static int bucketInt(int value, int bucketSize);
    static bool stringNullOrLengthZero(const std::string& str);

    static void initialize(); // Static method to initialize the SIN_TABLE
};