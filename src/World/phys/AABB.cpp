#include "AABB.h"


AABB::AABB(double _minX, double _minY, double _minZ, double _maxX, double _maxY, double _maxZ){
	this->minX = _minX;
	this->minY = _minY;
	this->minZ = _minZ;
	this->maxX = _maxX;
	this->maxY = _maxY;
	this->maxZ = _maxZ;
}


AABB* AABB::offset(double xo, double yo, double zo){
	this->minX += xo;
	this->minY += yo;
	this->minZ += zo;
	this->maxX += xo;
	this->maxY += yo;
	this->maxZ += zo;
	return;
}


AABB* AABB::setBounds(double minX, double minY, double minZ, double maxX, double maxY, double maxZ) {
	this->minX = minX;
	this->minY = minY;
	this->minZ = minZ;
	this->maxX = maxX;
	this->maxY = maxY;
	this->maxZ = maxZ;
	return;
}


double AABB::calculateXOffset(AABB* otherAABB, double output)
{
	if(otherAABB->maxY > this->minY && otherAABB->minY < this->maxY)
	{
		if(otherAABB->maxZ > this->minZ && otherAABB->minZ < this->maxZ)
		{
			double var4;
			if(output > 0.0 && otherAABB->maxX <= this->minX) {
				var4 = this->minX - otherAABB->maxX;
				if(var4 < output) {
					output = var4;
				}
			}
			if(output < 0.0 && otherAABB->minX >= this->maxX) {
				var4 = this->maxX - otherAABB->minX;
				if(var4 > output) {
					output = var4;
				}
			}

			return output;
		} 
		else{
			return output;
		}
	}else {
		return output;
	}
}


double AABB::calculateYOffset(AABB* otherAABB, double output)
{
	if(otherAABB->maxX > this->minX && otherAABB->minX < this->maxX)
	{
		if(otherAABB->maxZ > this->minZ && otherAABB->minZ < this->maxZ)
		{
			double var4;
			if(output > 0.0 && otherAABB->maxY <= this->minY) {
				var4 = this->minY - otherAABB->maxY;
				if(var4 < output) {
					output = var4;
				}
			}
			if(output < 0.0 && otherAABB->minY >= this->maxY) {
				var4 = this->maxY - otherAABB->minY;
				if(var4 > output) {
					output = var4;
				}
			}

			return output;
		} 
		else{
			return output;
		}
	}else {
		return output;
	}
}


double AABB::calculateZOffset(AABB* otherAABB, double output)
{
	if(otherAABB->maxX > this->minX && otherAABB->minX < this->maxX)
	{
		if(otherAABB->maxY > this->minY && otherAABB->minY < this->maxY)
		{
			double var4;
			if(output > 0.0 && otherAABB->maxZ <= this->minZ) {
				var4 = this->minZ - otherAABB->maxZ;
				if(var4 < output) {
					output = var4;
				}
			}
			if(output < 0.0 && otherAABB->minZ >= this->maxZ) {
				var4 = this->maxZ - otherAABB->minZ;
				if(var4 > output) {
					output = var4;
				}
			}

			return output;
		} 
		else{
			return output;
		}
	}else {
		return output;
	}
}

void test(){

}

bool AABB::intersectsWith(AABB* other) {
	return other->maxX > this->minX && other->minX < this->maxX ? (other->maxY > this->minY && other->minY < this->maxY ? other->maxZ > this->minZ && other->minZ < this->maxZ : false) : false;
}

bool AABB::isVecInside(Vec3D* vec) {
	return vec->xCoord > this->minX && vec->xCoord < this->maxX ? (vec->yCoord > this->minY && vec->yCoord < this->maxY ? vec->zCoord > this->minZ && vec->zCoord < this->maxZ : false) : false;
}

double AABB::getAverageEdgeLength() {
	return ((this->maxX - this->minX) + (this->maxY - this->minY) + (this->maxZ - this->minZ)) / 3.0;
}

void AABB::setBB(AABB* newBB) {
	this->minX = newBB->minX;
	this->minY = newBB->minY;
	this->minZ = newBB->minZ;
	this->maxX = newBB->maxX;
	this->maxY = newBB->maxY;
	this->maxZ = newBB->maxZ;
}