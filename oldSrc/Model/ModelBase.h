#pragma once

#include "../World/Entity/EntityLiving.h"

class ModelBase {
public:
    float onGround;
    bool isRiding;

    ModelBase() : onGround(0.0f), isRiding(false) {}
    virtual ~ModelBase() {}

    virtual void render(float var1, float var2, float var3, float var4, float var5, float var6) const { }
    virtual void setRotationAngles(float var1, float var2, float var3, float var4, float var5, float var6) const { }
    virtual void setLivingAnimations(EntityLiving* var1, float var2, float var3, float var4) const { }
};

