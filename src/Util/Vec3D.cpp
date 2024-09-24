#include "Vec3D.h"

std::vector<Vec3D*> Vec3D::vectorList;
int Vec3D::nextVector = 0;

Vec3D* Vec3D::createVectorHelper(double x, double y, double z) {
    return new Vec3D(x, y, z);
}

/*void Vec3D::func_28215_a() {
    for (Vec3D* vec : vectorList) 
    {
        delete vec;
    }
    vectorList.clear();
    nextVector = 0;
}*/

void Vec3D::initialize() {
    nextVector = 0;
}

Vec3D* Vec3D::createVector(double x, double y, double z) {
    if (nextVector >= vectorList.size()) {
        vectorList.push_back(createVectorHelper(0.0, 0.0, 0.0));
    }
    return vectorList[nextVector++]->setComponents(x, y, z);
}

Vec3D::Vec3D(double x, double y, double z)
    : xCoord(x == -0.0 ? 0.0 : x),
    yCoord(y == -0.0 ? 0.0 : y),
    zCoord(z == -0.0 ? 0.0 : z) {}

Vec3D* Vec3D::setComponents(double x, double y, double z) {
    this->xCoord = x;
    this->yCoord = y;
    this->zCoord = z;
    return this;
}

Vec3D* Vec3D::subtract(const Vec3D* vec) const {
    return createVector(vec->xCoord - this->xCoord, vec->yCoord - this->yCoord, vec->zCoord - this->zCoord);
}

Vec3D* Vec3D::normalize() const {
    double length = lengthVector();
    return (length < 1.0E-4) ? createVector(0.0, 0.0, 0.0) : createVector(this->xCoord / length, this->yCoord / length, this->zCoord / length);
}

Vec3D* Vec3D::crossProduct(const Vec3D* vec) const {
    return createVector(this->yCoord * vec->zCoord - this->zCoord * vec->yCoord,
        this->zCoord * vec->xCoord - this->xCoord * vec->zCoord,
        this->xCoord * vec->yCoord - this->yCoord * vec->xCoord);
}

Vec3D* Vec3D::addVector(double x, double y, double z) const {
    return createVector(this->xCoord + x, this->yCoord + y, this->zCoord + z);
}

double Vec3D::distanceTo(const Vec3D* vec) const {
    double dx = vec->xCoord - this->xCoord;
    double dy = vec->yCoord - this->yCoord;
    double dz = vec->zCoord - this->zCoord;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

double Vec3D::squareDistanceTo(const Vec3D* vec) const {
    double dx = vec->xCoord - this->xCoord;
    double dy = vec->yCoord - this->yCoord;
    double dz = vec->zCoord - this->zCoord;
    return dx * dx + dy * dy + dz * dz;
}

double Vec3D::squareDistanceTo(double x, double y, double z) const {
    double dx = x - this->xCoord;
    double dy = y - this->yCoord;
    double dz = z - this->zCoord;
    return dx * dx + dy * dy + dz * dz;
}

double Vec3D::lengthVector() const {
    return sqrt(this->xCoord * this->xCoord + this->yCoord * this->yCoord + this->zCoord * this->zCoord);
}

Vec3D* Vec3D::getIntermediateWithXValue(const Vec3D* vec, double x) const {
    double dx = vec->xCoord - this->xCoord;
    double dy = vec->yCoord - this->yCoord;
    double dz = vec->zCoord - this->zCoord;
    if (dx * dx < 1.0E-7) {
        return nullptr;
    }
    double t = (x - this->xCoord) / dx;
    return (t >= 0.0 && t <= 1.0) ? createVector(this->xCoord + dx * t, this->yCoord + dy * t, this->zCoord + dz * t) : nullptr;
}

Vec3D* Vec3D::getIntermediateWithYValue(const Vec3D* vec, double y) const {
    double dx = vec->xCoord - this->xCoord;
    double dy = vec->yCoord - this->yCoord;
    double dz = vec->zCoord - this->zCoord;
    if (dy * dy < 1.0E-7) {
        return nullptr;
    }
    double t = (y - this->yCoord) / dy;
    return (t >= 0.0 && t <= 1.0) ? createVector(this->xCoord + dx * t, this->yCoord + dy * t, this->zCoord + dz * t) : nullptr;
}

Vec3D* Vec3D::getIntermediateWithZValue(const Vec3D* vec, double z) const {
    double dx = vec->xCoord - this->xCoord;
    double dy = vec->yCoord - this->yCoord;
    double dz = vec->zCoord - this->zCoord;
    if (dz * dz < 1.0E-7) {
        return nullptr;
    }
    double t = (z - this->zCoord) / dz;
    return (t >= 0.0 && t <= 1.0) ? createVector(this->xCoord + dx * t, this->yCoord + dy * t, this->zCoord + dz * t) : nullptr;
}

std::string Vec3D::toString() const {
    std::ostringstream oss;
    oss << "(" << this->xCoord << ", " << this->yCoord << ", " << this->zCoord << ")";
    return oss.str();
}

void Vec3D::rotateAroundX(float angle) {
    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);
    double newY = this->yCoord * cosAngle - this->zCoord * sinAngle;
    double newZ = this->yCoord * sinAngle + this->zCoord * cosAngle;
    this->yCoord = newY;
    this->zCoord = newZ;
}

void Vec3D::rotateAroundY(float angle) {
    float cosAngle = std::cos(angle);
    float sinAngle = std::sin(angle);
    double newX = this->xCoord * cosAngle + this->zCoord * sinAngle;
    double newZ = this->zCoord * cosAngle - this->xCoord * sinAngle;
    this->xCoord = newX;
    this->zCoord = newZ;
}
