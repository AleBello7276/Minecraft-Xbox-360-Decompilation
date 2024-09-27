#pragma once

#include "../Util/PositionTextureVertex.h"
#include "../Util/TexturedQuad.h"
#include <vector>

class ModelRenderer
{
private:
    PositionTextureVertex* corners[8];
	std::vector<TexturedQuad> faces;
	int textureOffsetX;
	int textureOffsetY;
    bool compiled;
	int displayList;
    

public:
    float rotationPointX;
	float rotationPointY;
	float rotationPointZ;
	float rotateAngleX;
	float rotateAngleY;
	float rotateAngleZ;
    bool mirror;

    ModelRenderer(int var1, int var2);

    void addBox(float var1, float var2, float var3, int var4, int var5, int var6);
	void addBox(float var1, float var2, float var3, int var4, int var5, int var6, float var7);

    void setRotationPoint(float var1, float var2, float var3);

};