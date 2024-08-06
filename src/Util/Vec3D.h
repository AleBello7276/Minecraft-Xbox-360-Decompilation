#pragma once

#include <vector>
#include <string>

class Vec3D {
public:
    double xCoord;
    double yCoord;
    double zCoord;

    // Static methods
    static Vec3D* createVectorHelper(double x, double y, double z);
    static void func_28215_a();
    static void initialize();
    static Vec3D* createVector(double x, double y, double z);

    // Constructors
    Vec3D(double x, double y, double z);

    // Member methods
    Vec3D* setComponents(double x, double y, double z);
    Vec3D* subtract(const Vec3D* vec) const;
    Vec3D* normalize() const;
    Vec3D* crossProduct(const Vec3D* vec) const;
    Vec3D* addVector(double x, double y, double z) const;
    double distanceTo(const Vec3D* vec) const;
    double squareDistanceTo(const Vec3D* vec) const;
    double squareDistanceTo(double x, double y, double z) const;
    double lengthVector() const;
    Vec3D* getIntermediateWithXValue(const Vec3D* vec, double x) const;
    Vec3D* getIntermediateWithYValue(const Vec3D* vec, double y) const;
    Vec3D* getIntermediateWithZValue(const Vec3D* vec, double z) const;
    std::string toString() const;
    void rotateAroundX(float angle);
    void rotateAroundY(float angle);

private:
    static std::vector<Vec3D*> vectorList;
    static int nextVector;
};