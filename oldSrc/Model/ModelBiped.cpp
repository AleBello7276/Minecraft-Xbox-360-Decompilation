#include "ModelBiped.h"




ModelBiped::ModelBiped(float var1, float var2) 
{
	this->field_1279_h = false;
	this->field_1278_i = false;
	this->isSneak = false;
	this->bipedCloak = new ModelRenderer(0, 0);
	this->bipedCloak->addBox(-5.0F, 0.0F, -1.0F, 10, 16, 1, var1);
	this->bipedEars = new ModelRenderer(24, 0);
	this->bipedEars->addBox(-3.0F, -6.0F, -1.0F, 6, 6, 1, var1);
	this->bipedHead = new ModelRenderer(0, 0);
	this->bipedHead->addBox(-4.0F, -8.0F, -4.0F, 8, 8, 8, var1);
	this->bipedHead->setRotationPoint(0.0F, 0.0F + var2, 0.0F);
	this->bipedHeadwear = new ModelRenderer(32, 0);
	this->bipedHeadwear->addBox(-4.0F, -8.0F, -4.0F, 8, 8, 8, var1 + 0.5F);
	this->bipedHeadwear->setRotationPoint(0.0F, 0.0F + var2, 0.0F);
	this->bipedBody = new ModelRenderer(16, 16);
	this->bipedBody->addBox(-4.0F, 0.0F, -2.0F, 8, 12, 4, var1);
	this->bipedBody->setRotationPoint(0.0F, 0.0F + var2, 0.0F);
	this->bipedRightArm = new ModelRenderer(40, 16);
	this->bipedRightArm->addBox(-3.0F, -2.0F, -2.0F, 4, 12, 4, var1);
	this->bipedRightArm->setRotationPoint(-5.0F, 2.0F + var2, 0.0F);
	this->bipedLeftArm = new ModelRenderer(40, 16);
	this->bipedLeftArm->mirror = true;
	this->bipedLeftArm->addBox(-1.0F, -2.0F, -2.0F, 4, 12, 4, var1);
	this->bipedLeftArm->setRotationPoint(5.0F, 2.0F + var2, 0.0F);
	this->bipedRightLeg = new ModelRenderer(0, 16);
	this->bipedRightLeg->addBox(-2.0F, 0.0F, -2.0F, 4, 12, 4, var1);
	this->bipedRightLeg->setRotationPoint(-2.0F, 12.0F + var2, 0.0F);
	this->bipedLeftLeg = new ModelRenderer(0, 16);
	this->bipedLeftLeg->mirror = true;
	this->bipedLeftLeg->addBox(-2.0F, 0.0F, -2.0F, 4, 12, 4, var1);
	this->bipedLeftLeg->setRotationPoint(2.0F, 12.0F + var2, 0.0F);
}



void ModelBiped::render(float var1, float var2, float var3, float var4, float var5, float var6) const
{
    // TODO
}

void ModelBiped::setRotationAngles(float var1, float var2, float var3, float var4, float var5, float var6) const
{
    // TODO
}