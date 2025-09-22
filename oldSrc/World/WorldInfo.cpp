#include "WorldInfo.h"

// TODO

long WorldInfo::getRandomSeed() {
	return this->randomSeed;
}

int WorldInfo::getSpawnX() {
	return this->spawnX;
}

int WorldInfo::getSpawnY() {
	return this->spawnY;
}

int WorldInfo::getSpawnZ() {
	return this->spawnZ;
}

long WorldInfo::getWorldTime() {
	return this->worldTime;
}

long WorldInfo::getSizeOnDisk() {
	return this->sizeOnDisk;
}

NBTTagCompound* WorldInfo::getPlayerNBTTagCompound() {
	return this->playerTag;
}

int WorldInfo::getDimension() {
	return this->dimension;
}

void WorldInfo::setSpawnX(int var1) {
	this->spawnX = var1;
}

void WorldInfo::setSpawnY(int var1) {
	this->spawnY = var1;
}

void WorldInfo::setSpawnZ(int var1) {
	this->spawnZ = var1;
}

void WorldInfo::setWorldTime(long var1) {
	this->worldTime = var1;
}

void WorldInfo::setSizeOnDisk(long var1) {
	this->sizeOnDisk = var1;
}

void WorldInfo::setPlayerNBTTagCompound(NBTTagCompound* var1) {
	this->playerTag = var1;
}

void WorldInfo::setSpawn(int var1, int var2, int var3) {
	this->spawnX = var1;
	this->spawnY = var2;
	this->spawnZ = var3;
}
std::string WorldInfo::getWorldName() {
	return this->levelName;
}

void WorldInfo::setWorldName(std::string  var1) {
	this->levelName = var1;
}
int WorldInfo::getSaveVersion() {
	return this->saveVersion;
}
void WorldInfo::setSaveVersion(int var1) {
	this->saveVersion = var1;
}
long WorldInfo::getLastTimePlayed() {
	return this->lastTimePlayed;
}
bool WorldInfo::getThundering() {
	return this->thundering;
}
void WorldInfo::setThundering(bool var1) {
	this->thundering = var1;
}
int WorldInfo::getThunderTime() {
	return this->thunderTime;
}
void WorldInfo::setThunderTime(int var1) {
	this->thunderTime = var1;
}
bool WorldInfo::getRaining() {
	return this->raining;
}
void WorldInfo::setRaining(bool var1) {
	this->raining = var1;
}
int WorldInfo::getRainTime() {
	return this->rainTime;
}
void WorldInfo::setRainTime(int var1) {
	this->rainTime = var1;
}