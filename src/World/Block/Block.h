#pragma once

#include "Material/Material.h"
#include "StepSound.h"

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


protected:
    Block(int var1, Material var2);
    Block(int var1, int var2, Material var3);
    float blockHardness;
	float blockResistance;


// vftable
protected:
    virtual Block* setResistance(float var1);
public:
    virtual bool renderAsNormalBlock();
    virtual int Block::getRenderType() = 0;
protected:
    virtual Block* setHardness(float var1) = 0; 
    virtual Block* setTickOnLoad(bool param_2) = 0;
public:
    virtual void setBlockBounds(float param_1, float param_2, float param_3, float param_4, float param_5, float param_6) = 0;

    

};
