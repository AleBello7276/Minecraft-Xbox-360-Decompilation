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

protected:

    Block(int var1, Material var2);
    Block(int var1, int var2, Material var3);
};
