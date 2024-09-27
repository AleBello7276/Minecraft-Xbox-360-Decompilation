#pragma once

#include "ModelBase.h"
#include "../Renderer/ModelRenderer.h"

class ModelBiped : public ModelBase
{

public:
    ModelRenderer* bipedHead;
	ModelRenderer* bipedHeadwear;
	ModelRenderer* bipedBody;
	ModelRenderer* bipedRightArm;
	ModelRenderer* bipedLeftArm;
	ModelRenderer* bipedRightLeg;
	ModelRenderer* bipedLeftLeg;
	ModelRenderer* bipedEars;
	ModelRenderer* bipedCloak;
	bool field_1279_h;
	bool field_1278_i;
	bool isSneak;

    
    ModelBiped() { ModelBiped(0.0f); }
    ModelBiped(float var1) { ModelBiped(var1, 0.0f); }
    ModelBiped(float var1, float var2);

    virtual ~ModelBiped() {}

    void render(float var1, float var2, float var3, float var4, float var5, float var6) const override;
    void setRotationAngles(float var1, float var2, float var3, float var4, float var5, float var6) const override;


};