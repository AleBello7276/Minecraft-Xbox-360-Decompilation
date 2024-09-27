#pragma once 

#include "../Block/IBlockAccess.h"
#include "../Java/Math/Random.h"
#include "Chunk/IChunkProvider.h"
#include "WorldInfo.h"
#include <array>

// TODO
class WorldProvider;
class MapStorage;

class World : IBlockAccess
{
public:
    bool scheduledUpdatesAreImmediate;
	//List loadedEntityList;
	//List loadedTileEntityList;
	//List playerEntities;
	//List weatherEffects;
	int skylightSubtracted;
	int field_27172_i;
	bool editingBlocks;
	int difficultySetting;
	Random* rand;
	bool isNewWorld;
	const WorldProvider* worldProvider;
	bool findingSpawnPoint;
	MapStorage* field_28108_z;
	
	static const int field_9429_y = 0;
	bool multiplayerWorld;

private:
    //List unloadedEntityList;
	//TreeSet scheduledTickTreeSet;
	//Set scheduledTickSet;
    //List lightingToUpdate;
    long field_1019_F;
    std::array<AxisAlignedBB> collidingBoundingBoxes;
    bool allPlayersSleeping;
	int field_4204_J;
	bool spawnHostileMobs;
	bool spawnPeacefulMobs;
    long lockTimestamp;
    //Set positionsToUpdate;
	int soundCounter;
	//List field_1012_M;

protected:
    //List worldAccesses;
	IChunkProvider* chunkProvider;
	const ISaveHandler saveHandler;
	WorldInfo* worldInfo;
    int field_9437_g;
	int field_9436_h;
	float prevRainingStrength;
	float rainingStrength;
	float prevThunderingStrength;
	float thunderingStrength;
	int field_27168_F;
    int autosavePeriod;

};