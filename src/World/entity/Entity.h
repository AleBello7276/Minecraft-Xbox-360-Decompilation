#pragma once

#include "../../Util/AxisAlignedBB.h"

class Entity {

public:
	double prevPosX;
	double prevPosY;
	double prevPosZ;
	double posX;
	double posY;
	double posZ;
	double motionX;
	double motionY;
	double motionZ;
	float rotationYaw;
	float rotationPitch;
	float prevRotationYaw;
	float prevRotationPitch;
	AxisAlignedBB boundingBox;
	bool onGround;
	bool isCollidedHorizontally;
	bool isCollidedVertically;
	bool isCollided;
	bool beenAttacked;
	bool isInWeb;
	bool field_9293_aM;
	bool isDead;
	float yOffset;
	float width = 0.6F;
	float height = 1.8F;
	float prevDistanceWalkedModified = 0.0F;
	float distanceWalkedModified = 0.0F;
	float fallDistance = 0.0F;
	double lastTickPosX;
	double lastTickPosY;
	double lastTickPosZ;
	float ySize;

	void setLocationAndAngles(double x, double y, double z, float yaw, float pitch);
	void setPosition(double x, double y, double z);
	void setSize(float width, float height);
	void setEntityDead();
	void setRotation(float yaw, float pitch);



private:
	int nextStepDistance = 1;


};