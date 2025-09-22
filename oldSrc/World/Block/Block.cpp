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


Block::Block(int var1, Material* var2) : maxZ(0.0), maxY(0.0), maxX(0.0), minZ(0.0), minY(0.0), minX(0.0),
                                        field_27035_bo(true), enableStats(true), blockHardness(0.0), blockResistance(0.0), blockMaterial(var2),
                                        stepSound(Block::soundPowderFootstep), blockParticleGravity(1.0), slipperiness(0.6)
{

    this->setBlockBounds(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
    Block::canBlockGrass[var1] = !var2->getCanBlockGrass();
    Block::opaqueCubeLookup[var1] = true;
}



Block::Block(int var1, int var2, Material* var3) : maxZ(0.0), maxY(0.0), maxX(0.0), minZ(0.0), minY(0.0), minX(0.0),
                                        field_27035_bo(true), enableStats(true), blockHardness(0.0), blockResistance(0.0), blockMaterial(var3),
                                        stepSound(Block::soundPowderFootstep), blockParticleGravity(1.0), slipperiness(0.6), blockIndexInTexture(var2)
{

    this->setBlockBounds(0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
    Block::canBlockGrass[var1] = !var3->getCanBlockGrass();
    Block::opaqueCubeLookup[var1] = true;
}
 



// 0x824da2c8
Block* Block::setStepSound(StepSound *param_2)
{
    this->stepSound = param_2;
    return this;
}

// 0x824da2d0
Block * Block::setLightOpacity(int param_2)
{
    Block::lightOpacity[this->blockID] = param_2;
    return this;
}

// 0x824da2e8
Block * Block::setLightValue(float param_1)
{
    Block::lightValue[this->blockID] = (int)(param_1 * 15.0);
    return this;
}

// 0x824da310
Block* Block::setResistance(float var1) 
{
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

// 0x824da328
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

// 0x824da3a0
float Block::getBlockBrightness(IBlockAccess *param_2,int param_3,int param_4,int param_5)
{
    return param_2->getBrightness(param_3,param_4,param_5, Block::lightValue[this->blockID]);
}