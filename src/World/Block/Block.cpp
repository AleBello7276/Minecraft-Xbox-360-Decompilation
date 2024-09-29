#include "Block.h"

StepSound
    *Block::soundPowderFootstep,
    *Block::soundWoodFootstep,
    *Block::soundGravelFootstep,
    *Block::soundGrassFootstep,
    *Block::soundStoneFootstep,
    *Block::soundMetalFootstep,
    *Block::soundGlassFootstep,
    *Block::soundClothFootstep,
    *Block::soundSandFootstep;


void Block::staticCtor()
{
    soundPowderFootstep = new StepSound("stone", 1.0F, 1.0F);
    soundWoodFootstep   = new StepSound("wood", 1.0F, 1.0F);
    soundGravelFootstep = new StepSound("gravel", 1.0F, 1.0F);
    soundGrassFootstep  = new StepSound("grass", 1.0F, 1.0F);
    soundStoneFootstep  = new StepSound("stone", 1.0F, 1.0F);
    soundMetalFootstep  = new StepSound("stone", 1.0F, 1.5F);
    soundGlassFootstep  = new StepSoundStone("stone", 1.0F, 1.0F);
    soundClothFootstep  = new StepSound("cloth", 1.0F, 1.0F);
    soundSandFootstep   = new StepSoundSand("sand", 1.0F, 1.0F);
}