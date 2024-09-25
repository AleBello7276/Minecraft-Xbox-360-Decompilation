// this is a test, 
// i'm experimenting, i'm trying to do something similar that the MCPE decompiler devs did with APP thing
//
//
#pragma once

#include "Minecraft.h"
#include "World/map/MapColor.h"
#include "Block/Material/Material.h"


class Game
{
public:
    Game();
    ~Game();

	void init(Minecraft* mc);
    void run(Minecraft* mc);
	void shutdown();

private:
    bool staticCtorsInitialized;
};