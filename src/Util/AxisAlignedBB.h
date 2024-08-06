#pragma once

#include <vector>
#include <string>
#include "Vec3D.h"

class AxisAlignedBB {
private:
    static std::vector<AxisAlignedBB*> boundingBoxes;
    static int numBoundingBoxesInUse;

public:
    double minX;
    double minY;
    double minZ;
    double maxX;
    double maxY;
    double maxZ;

    static AxisAlignedBB* getBoundingBox(double var0, double var2, double var4, double var6, double var8, double var10);
    static void func_28196_a();
    static void clearBoundingBoxPool();
    static AxisAlignedBB* getBoundingBoxFromPool(double var0, double var2, double var4, double var6, double var8, double var10);

    AxisAlignedBB(double var1, double var3, double var5, double var7, double var9, double var11);

    AxisAlignedBB* setBounds(double var1, double var3, double var5, double var7, double var9, double var11);
    AxisAlignedBB* addCoord(double var1, double var3, double var5);
    AxisAlignedBB* expand(double var1, double var3, double var5);
    AxisAlignedBB* getOffsetBoundingBox(double var1, double var3, double var5);
    double calculateXOffset(const AxisAlignedBB& var1, double var2) const;
    double calculateYOffset(const AxisAlignedBB& var1, double var2) const;
    double calculateZOffset(const AxisAlignedBB& var1, double var2) const;
    bool intersectsWith(const AxisAlignedBB& var1) const;
    AxisAlignedBB* offset(double var1, double var3, double var5);
    bool isVecInside(const Vec3D& var1) const;
    double getAverageEdgeLength() const;
    AxisAlignedBB* func_28195_e(double var1, double var3, double var5);
    AxisAlignedBB* copy() const;
    // MovingObjectPosition* func_1169_a(const Vec3D& var1, const Vec3D& var2) const; | must wait for MovingObjectPosition impl

private:
    bool isVecInYZ(const Vec3D& var1) const;
    bool isVecInXZ(const Vec3D& var1) const;
    bool isVecInXY(const Vec3D& var1) const;

public:
    void setBB(const AxisAlignedBB& var1);
    std::string toString() const;
};
