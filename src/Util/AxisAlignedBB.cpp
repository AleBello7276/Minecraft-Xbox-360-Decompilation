#include "AxisAlignedBB.h"

std::vector<AxisAlignedBB*> AxisAlignedBB::boundingBoxes;
int AxisAlignedBB::numBoundingBoxesInUse = 0;

AxisAlignedBB* AxisAlignedBB::getBoundingBox(double var0, double var2, double var4, double var6, double var8, double var10) {
    return new AxisAlignedBB(var0, var2, var4, var6, var8, var10);
}

void AxisAlignedBB::func_28196_a() {
    boundingBoxes.clear();
    numBoundingBoxesInUse = 0;
}

void AxisAlignedBB::clearBoundingBoxPool() {
    numBoundingBoxesInUse = 0;
}

AxisAlignedBB* AxisAlignedBB::getBoundingBoxFromPool(double var0, double var2, double var4, double var6, double var8, double var10) {
    if (numBoundingBoxesInUse >= boundingBoxes.size()) {
        boundingBoxes.push_back(getBoundingBox(0.0, 0.0, 0.0, 0.0, 0.0, 0.0));
    }

    return boundingBoxes[numBoundingBoxesInUse++]->setBounds(var0, var2, var4, var6, var8, var10);
}

AxisAlignedBB::AxisAlignedBB(double minX, double minY, double minZ, double maxX, double maxY, double maxZ) {
    this->minX = minX;
    this->minY = minY;
    this->minZ = minZ;
    this->maxX = maxX;
    this->maxY = maxY;
    this->maxZ = maxZ;
}

AxisAlignedBB* AxisAlignedBB::setBounds(double var1, double var3, double var5, double var7, double var9, double var11) {
    minX = var1;
    minY = var3;
    minZ = var5;
    maxX = var7;
    maxY = var9;
    maxZ = var11;
    return this;
}

AxisAlignedBB* AxisAlignedBB::addCoord(double var1, double var3, double var5) {
    double var7 = minX;
    double var9 = minY;
    double var11 = minZ;
    double var13 = maxX;
    double var15 = maxY;
    double var17 = maxZ;

    if (var1 < 0.0) var7 += var1;
    if (var1 > 0.0) var13 += var1;
    if (var3 < 0.0) var9 += var3;
    if (var3 > 0.0) var15 += var3;
    if (var5 < 0.0) var11 += var5;
    if (var5 > 0.0) var17 += var5;

    return getBoundingBoxFromPool(var7, var9, var11, var13, var15, var17);
}

AxisAlignedBB* AxisAlignedBB::expand(double var1, double var3, double var5) {
    double var7 = minX - var1;
    double var9 = minY - var3;
    double var11 = minZ - var5;
    double var13 = maxX + var1;
    double var15 = maxY + var3;
    double var17 = maxZ + var5;

    return getBoundingBoxFromPool(var7, var9, var11, var13, var15, var17);
}

AxisAlignedBB* AxisAlignedBB::getOffsetBoundingBox(double var1, double var3, double var5) {
    return getBoundingBoxFromPool(minX + var1, minY + var3, minZ + var5, maxX + var1, maxY + var3, maxZ + var5);
}

double AxisAlignedBB::calculateXOffset(const AxisAlignedBB& var1, double var2) const {
    if (var1.maxY > minY && var1.minY < maxY && var1.maxZ > minZ && var1.minZ < maxZ) {
        double var4;
        if (var2 > 0.0 && var1.maxX <= minX) {
            var4 = minX - var1.maxX;
            if (var4 < var2) var2 = var4;
        }
        if (var2 < 0.0 && var1.minX >= maxX) {
            var4 = maxX - var1.minX;
            if (var4 > var2) var2 = var4;
        }
    }
    return var2;
}

double AxisAlignedBB::calculateYOffset(const AxisAlignedBB& var1, double var2) const {
    if (var1.maxX > minX && var1.minX < maxX && var1.maxZ > minZ && var1.minZ < maxZ) {
        double var4;
        if (var2 > 0.0 && var1.maxY <= minY) {
            var4 = minY - var1.maxY;
            if (var4 < var2) var2 = var4;
        }
        if (var2 < 0.0 && var1.minY >= maxY) {
            var4 = maxY - var1.minY;
            if (var4 > var2) var2 = var4;
        }
    }
    return var2;
}

double AxisAlignedBB::calculateZOffset(const AxisAlignedBB& var1, double var2) const {
    if (var1.maxX > minX && var1.minX < maxX && var1.maxY > minY && var1.minY < maxY) {
        double var4;
        if (var2 > 0.0 && var1.maxZ <= minZ) {
            var4 = minZ - var1.maxZ;
            if (var4 < var2) var2 = var4;
        }
        if (var2 < 0.0 && var1.minZ >= maxZ) {
            var4 = maxZ - var1.minZ;
            if (var4 > var2) var2 = var4;
        }
    }
    return var2;
}

bool AxisAlignedBB::intersectsWith(const AxisAlignedBB& var1) const {
    return var1.maxX > minX && var1.minX < maxX && var1.maxY > minY && var1.minY < maxY && var1.maxZ > minZ && var1.minZ < maxZ;
}

AxisAlignedBB* AxisAlignedBB::offset(double var1, double var3, double var5) {
    minX += var1;
    minY += var3;
    minZ += var5;
    maxX += var1;
    maxY += var3;
    maxZ += var5;
    return this;
}

bool AxisAlignedBB::isVecInside(const Vec3D& var1) const {
    return var1.xCoord > minX && var1.xCoord < maxX && var1.yCoord > minY && var1.yCoord < maxY && var1.zCoord > minZ && var1.zCoord < maxZ;
}

double AxisAlignedBB::getAverageEdgeLength() const {
    double var1 = maxX - minX;
    double var3 = maxY - minY;
    double var5 = maxZ - minZ;
    return (var1 + var3 + var5) / 3.0;
}

AxisAlignedBB* AxisAlignedBB::func_28195_e(double var1, double var3, double var5) {
    double var7 = minX + var1;
    double var9 = minY + var3;
    double var11 = minZ + var5;
    double var13 = maxX - var1;
    double var15 = maxY - var3;
    double var17 = maxZ - var5;

    return getBoundingBoxFromPool(var7, var9, var11, var13, var15, var17);
}

AxisAlignedBB* AxisAlignedBB::copy() const {
    return getBoundingBoxFromPool(minX, minY, minZ, maxX, maxY, maxZ);
}

bool AxisAlignedBB::isVecInYZ(const Vec3D& var1) const {
    return var1.yCoord >= minY && var1.yCoord <= maxY && var1.zCoord >= minZ && var1.zCoord <= maxZ;
}

bool AxisAlignedBB::isVecInXZ(const Vec3D& var1) const {
    return var1.xCoord >= minX && var1.xCoord <= maxX && var1.zCoord >= minZ && var1.zCoord <= maxZ;
}

bool AxisAlignedBB::isVecInXY(const Vec3D& var1) const {
    return var1.xCoord >= minX && var1.xCoord <= maxX && var1.yCoord >= minY && var1.yCoord <= maxY;
}

void AxisAlignedBB::setBB(const AxisAlignedBB& var1) {
    minX = var1.minX;
    minY = var1.minY;
    minZ = var1.minZ;
    maxX = var1.maxX;
    maxY = var1.maxY;
    maxZ = var1.maxZ;
}

std::string AxisAlignedBB::toString() const {
    return "box[" + std::to_string(minX) + ", " + std::to_string(minY) + ", " + std::to_string(minZ) + " -> " +
        std::to_string(maxX) + ", " + std::to_string(maxY) + ", " + std::to_string(maxZ) + "]";
}