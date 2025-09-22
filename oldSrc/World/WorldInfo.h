#pragma once

#include <string>
#include "Nbt/NBTTagCompound.h"

class WorldInfo {
private:
	long randomSeed;
	int spawnX;
	int spawnY;
	int spawnZ;
	long worldTime;
	long lastTimePlayed;
	long sizeOnDisk;
	NBTTagCompound* playerTag;
	int dimension;
	std::string levelName;
	int saveVersion;
	bool raining;
	int rainTime;
	bool thundering;
	int thunderTime;
public:
	WorldInfo(NBTTagCompound* var1);

	WorldInfo(long var1, std::string var3);

	WorldInfo(WorldInfo* var1);

	NBTTagCompound* getNBTTagCompound();

	NBTTagCompound* getNBTTagCompoundWithPlayer(/*List var1*/);

	void updateTagCompound(NBTTagCompound* var1, NBTTagCompound* var2);


	long getRandomSeed();
	int getSpawnX();
	int getSpawnY();
	int getSpawnZ();
	long getWorldTime();
	long getSizeOnDisk();
	NBTTagCompound* getPlayerNBTTagCompound();
	int getDimension();
	void setSpawnX(int var1);
	void setSpawnY(int var1);
	void setSpawnZ(int var1);
	void setWorldTime(long var1);
	void setSizeOnDisk(long var1);
	void setPlayerNBTTagCompound(NBTTagCompound* var1);
	void setSpawn(int var1, int var2, int var3);
	std::string getWorldName();
	void setWorldName(std::string var1);
	int getSaveVersion();
	void setSaveVersion(int var1);
	long getLastTimePlayed();
	bool getThundering();
	void setThundering(bool var1); 
	int getThunderTime();
	void setThunderTime(int var1); 
	bool getRaining() ;
	void setRaining(bool var1);
	int getRainTime() ;
	void setRainTime(int var1);
};
