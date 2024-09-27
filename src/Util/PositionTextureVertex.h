#pragma once
#pragma once

#include "Vec3D.h"

class PositionTextureVertex {

public:
    Vec3D* vector3D;
	float texturePositionX;
	float texturePositionY;

    PositionTextureVertex::PositionTextureVertex(float var1, float var2, float var3, float var4, float var5) 
    {
        PositionTextureVertex(Vec3D::createVectorHelper((double)var1, (double)var2, (double)var3), var4, var5);
    }

    PositionTextureVertex::PositionTextureVertex(PositionTextureVertex* var1, float var2, float var3) 
    {
        this->vector3D = var1->vector3D;
        this->texturePositionX = var2;
        this->texturePositionY = var3;
    }
    PositionTextureVertex::PositionTextureVertex(Vec3D* var1, float var2, float var3) 
    {
        this->vector3D = var1;
        this->texturePositionX = var2;
        this->texturePositionY = var3;
    }

    PositionTextureVertex* setTexturePosition(float var1, float var2) 
    {
        return new PositionTextureVertex(this, var1, var2);
    }
};