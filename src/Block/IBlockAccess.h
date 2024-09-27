#pragma omce

#include "Material/Material.h"

// TODO
class WorldChunkManager;
class TileEntity;

class IBlockAccess 
{
	virtual int getBlockId(int var1, int var2, int var3) const { }
	virtual TileEntity* getBlockTileEntity(int var1, int var2, int var3) const { }
	virtual float getBrightness(int var1, int var2, int var3, int var4) const { }
	virtual float getLightBrightness(int var1, int var2, int var3) const { }
	virtual int getBlockMetadata(int var1, int var2, int var3) const { }
	virtual Material* getBlockMaterial(int var1, int var2, int var3) const { }
	virtual bool isBlockOpaqueCube(int var1, int var2, int var3) const { }
	virtual bool func_28100_h(int var1, int var2, int var3) const { }
	virtual WorldChunkManager* getWorldChunkManager() const { }
};
