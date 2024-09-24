#include "Entity.h"


Entity::Entity()
{
	this->boundingBox = new AxisAlignedBB(1,1,1,1,1,1);
	this->width = 0.6F;
	this->height = 1.8F;
	this->prevDistanceWalkedModified = 0.0F;
	this->distanceWalkedModified = 0.0F;
	this->fallDistance = 0.0F;
	this->nextStepDistance = 1;
}


//set if entity is dead or not
void Entity::setEntityDead(){
  this->isDead = true;
  return;
}

//set entity size
void Entity::setSize(float width, float height) {
	this->width = width;
	this->height = height;
}

//set enity rotation
void Entity::setRotation(float yaw, float pitch) {
	  if (360.0 <= yaw) {
    do {
      yaw = yaw - 360.0;
    } while (360.0 <= yaw);
  }
  if (360.0 <= pitch) {
    do {
      pitch = pitch - 360.0;
    } while (360.0 <= pitch);
  }
  this->rotationPitch = pitch;
  this->rotationYaw = yaw;
  return;
}

//set both position and angles
void Entity::setLocationAndAngles(double x, double y, double z, float yaw, float pitch) {
	this->lastTickPosX = this->prevPosX = this->posX = x;
	this->lastTickPosY = this->prevPosY = this->posY = y + (double)this->yOffset;
	this->lastTickPosZ = this->prevPosZ = this->posZ = z;
	this->rotationYaw = yaw;
	this->rotationPitch = pitch;
	this->setPosition(this->posX, this->posY, this->posZ);
}

//set entity position
void Entity::setPosition(double x, double y, double z){
	this->posX = x;
	this->posY = y;
	this->posZ = z;
	float var7 = this->width / 2.0F;
	float var8 = this->height;
	this->boundingBox->setBounds(x - (double)var7, y - (double)this->yOffset + (double)this->ySize, z - (double)var7, x + (double)var7, y - (double)this->yOffset + (double)this->ySize + (double)var8, z + (double)var7);
}