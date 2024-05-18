#pragma once

#include "Vec3D.h"

class AABB
{
public:
	double minX;
	double minY;
	double minZ;
	double maxX;
	double maxY;
	double maxZ;

	AABB(double minX, double minY, double minZ, double maxX, double maxY, double maxZ);	
	

	AABB* offset(double x, double y, double z);
	double calculateXOffset(AABB* otherAABB, double output); //param 2 "Output"?? idk
	double calculateYOffset(AABB* otherAABB, double output); //param 2 "Output"?? idk
	double calculateZOffset(AABB* otherAABB, double output); //param 2 "Output"?? idk
	bool intersectsWith(AABB* other);
	bool isVecInside(Vec3D* vec);
	double getAverageEdgeLength();
	void setBB(AABB* newBB);
	AABB* setBounds(double minX, double minY, double minZ, double maxX, double maxY, double maxZ);

private:



};
