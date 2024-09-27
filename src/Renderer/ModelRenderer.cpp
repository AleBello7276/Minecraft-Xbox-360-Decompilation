#include "ModelRenderer.h"

ModelRenderer::ModelRenderer(int var1, int var2) : mirror(false), displayList(0), compiled(false)
{
    this->textureOffsetX = var1;
	this->textureOffsetY = var2;
}

void ModelRenderer::addBox(float var1, float var2, float var3, int var4, int var5, int var6) 
{
	this->addBox(var1, var2, var3, var4, var5, var6, 0.0F);
}

void ModelRenderer::addBox(float var1, float var2, float var3, int var4, int var5, int var6, float var7) 
{
	/*this->corners = new PositionTextureVertex[8];
	this->faces.resize(6);
	float var8 = var1 + (float)var4;
	float var9 = var2 + (float)var5;
	float var10 = var3 + (float)var6;
	var1 -= var7;
	var2 -= var7;
	var3 -= var7;
	var8 += var7;
	var9 += var7;
	var10 += var7;
	if(this->mirror) {
		float var11 = var8;
		var8 = var1;
		var1 = var11;
	}

	this->corners[0] = new PositionTextureVertex(var1, var2, var3, 0.0f, 0.0f);
    this->corners[1] = new PositionTextureVertex(var8, var2, var3, 0.0f, 8.0f);
    this->corners[2] = new PositionTextureVertex(var8, var9, var3, 8.0f, 8.0f);
    this->corners[3] = new PositionTextureVertex(var1, var9, var3, 8.0f, 0.0f);
    this->corners[4] = new PositionTextureVertex(var1, var2, var10, 0.0f, 0.0f);
    this->corners[5] = new PositionTextureVertex(var8, var2, var10, 0.0f, 8.0f);
    this->corners[6] = new PositionTextureVertex(var8, var9, var10, 8.0f, 8.0f);
    this->corners[7] = new PositionTextureVertex(var1, var9, var10, 8.0f, 0.0f);
    
    PositionTextureVertex* f0[4] = {this->corners[5], this->corners[1], this->corners[2], this->corners[6]};
	this->faces[0] =   TexturedQuad(f0, this->textureOffsetX + var6 + var4, this->textureOffsetY + var6, this->textureOffsetX + var6 + var4 + var6, this->textureOffsetY + var6 + var5);
	//this->faces[1] = TexturedQuad({this->corners[0], this->corners[4], this->corners[7], this->corners[3]}, this->textureOffsetX + 0, this->textureOffsetY + var6, this->textureOffsetX + var6, this->textureOffsetY + var6 + var5);
	//this->faces[2] = TexturedQuad({this->corners[5], this->corners[4], this->corners[0], this->corners[1]}, this->textureOffsetX + var6, this->textureOffsetY + 0, this->textureOffsetX + var6 + var4, this->textureOffsetY + var6);
	//this->faces[3] = TexturedQuad({this->corners[2], this->corners[3], this->corners[7], this->corners[6]}, this->textureOffsetX + var6 + var4, this->textureOffsetY + 0, this->textureOffsetX + var6 + var4 + var4, this->textureOffsetY + var6);
	//this->faces[4] = TexturedQuad({this->corners[1], this->corners[0], this->corners[3], this->corners[2]}, this->textureOffsetX + var6, this->textureOffsetY + var6, this->textureOffsetX + var6 + var4, this->textureOffsetY + var6 + var5);
	//this->faces[5] = TexturedQuad({this->corners[4], this->corners[5], this->corners[6], this->corners[7]}, this->textureOffsetX + var6 + var4 + var6, this->textureOffsetY + var6, this->textureOffsetX + var6 + var4 + var6 + var4, this->textureOffsetY + var6 + var5);
	
    
    if(this->mirror) 
    {
        for(TexturedQuad face : this->faces)
        {
            face.flipFace();
        }	
	}*/
}


void ModelRenderer::setRotationPoint(float var1, float var2, float var3) 
{
    this->rotationPointX = var1;
    this->rotationPointY = var2;
    this->rotationPointZ = var3;
}