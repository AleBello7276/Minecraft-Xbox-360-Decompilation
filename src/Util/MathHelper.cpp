#include "MathHelper.h"

#define PI 3.141592653589793

float MathHelper::SIN_TABLE[65536];

void MathHelper::initialize() {
    for (int i = 0; i < 65536; ++i) {
        SIN_TABLE[i] = std::sin(static_cast<double>(i) * PI * 2.0 / 65536.0);
    }
}

float MathHelper::sin(float value) 
{
    if (SIN_TABLE == NULL)
    {
        initialize();
    }

    return SIN_TABLE[static_cast<int>(value * 10430.378F) & 0xFFFF];
}

float MathHelper::cos(float value) 
{
    if (SIN_TABLE == NULL)
    {
        initialize();
    }

    return SIN_TABLE[(static_cast<int>(value * 10430.378F + 16384.0F)) & 0xFFFF];
}

float MathHelper::sqrt_float(float value) {
    return std::sqrt(value);
}

float MathHelper::sqrt_double(double value) {
    return std::sqrt(value);
}

int MathHelper::floor_float(float value) {
    int i = static_cast<int>(value);
    return value < static_cast<float>(i) ? i - 1 : i;
}

int MathHelper::floor_double(double value) {
    int i = static_cast<int>(value);
    return value < static_cast<double>(i) ? i - 1 : i;
}

float MathHelper::abs(float value) {
    return value >= 0.0F ? value : -value;
}

double MathHelper::abs_max(double value1, double value2) {
    value1 = (value1 < 0.0) ? -value1 : value1;
    value2 = (value2 < 0.0) ? -value2 : value2;
    return (value1 > value2) ? value1 : value2;
}

int MathHelper::bucketInt(int value, int bucketSize) {
    return value < 0 ? -((-value - 1) / bucketSize) - 1 : value / bucketSize;
}

bool MathHelper::stringNullOrLengthZero(const std::string& str) {
    return str.empty();
}