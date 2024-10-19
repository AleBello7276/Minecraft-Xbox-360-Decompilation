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



Block* Block::blocksList[256] = {nullptr};
bool Block::tickOnLoad[256] = {false};
bool Block::opaqueCubeLookup[256] = {false};
bool Block::isBlockContainer[256] = {false};
int Block::lightOpacity[256] = {0};
bool Block::canBlockGrass[256] = {false};
int Block::lightValue[256] = {0};
bool Block::field_28032_t[256] = {false};


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

Block* Block::setResistance(float var1) {
	this->blockResistance = var1 * 3.0F;
	return this;
}

bool Block::renderAsNormalBlock()
{
    return true;
}

int Block::getRenderType()
{
    return 0;
}

Block* Block::setHardness(float var1) 
{
	this->blockHardness = var1;
	if(this->blockResistance < var1 * 5.0F) {
		this->blockResistance = var1 * 5.0F;
	}
	return this;
}

Block* Block::setTickOnLoad(bool param_2) 
{
    Block::tickOnLoad[this->blockID] = param_2;
    return this;
}
 

// 0x824da380
void Block::setBlockBounds(float param_1,float param_2,float param_3,float param_4,float param_5,float param_6)
{
    this->minX = (double)param_1;
    this->minY = (double)param_2;
    this->minZ = (double)param_3; 
    this->maxX = (double)param_4;
    this->maxY = (double)param_5;
    this->maxZ = (double)param_6;
} 