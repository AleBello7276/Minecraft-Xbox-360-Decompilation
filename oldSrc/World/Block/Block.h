#pragma once

#include "Material/Material.h"
#include "StepSound.h"
#include "IBlockAccess.h"

class Block
{
public:

    static StepSound 
            *soundPowderFootstep,
            *soundWoodFootstep,
            *soundGravelFootstep,
            *soundGrassFootstep,
            *soundStoneFootstep,
            *soundMetalFootstep,
            *soundGlassFootstep,
            *soundClothFootstep,
            *soundSandFootstep;


    
    //staticCtor
    
    static void staticCtor();

    static Block* blocksList[256];
    static bool tickOnLoad[256];
    static bool opaqueCubeLookup[256];
    static bool isBlockContainer[256];
    static int lightOpacity[256];
    static bool canBlockGrass[256];
    static int lightValue[256];
    static bool field_28032_t[256];

    double minX;
	double minY;
	double minZ;
	double maxX;
	double maxY;
	double maxZ;
    int blockID;
    int blockIndexInTexture;
    StepSound* stepSound;
    float blockParticleGravity;
    Material* blockMaterial;
	float slipperiness;
    Block(int var1, Material* var2);
    Block(int var1, int var2, Material* var3);

protected:
    float blockHardness;
	float blockResistance;
    bool field_27035_bo;
	bool enableStats;


// vftable
protected:
    virtual Block* setStepSound(StepSound *param_2) = 0;
    virtual Block * setLightOpacity(int param_2) = 0;
    virtual Block* setLightValue(float param_1) = 0;
    virtual Block* setResistance(float var1) = 0;
public:
    virtual bool renderAsNormalBlock() = 0;
    virtual int Block::getRenderType() = 0;
protected:
    virtual Block* setHardness(float var1) = 0; 
    virtual Block* setTickOnLoad(bool param_2) = 0;
public:
    virtual void setBlockBounds(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6) = 0;
    virtual float getBlockBrightness(IBlockAccess *param_2,int param_3,int param_4,int param_5) = 0;

    

};
