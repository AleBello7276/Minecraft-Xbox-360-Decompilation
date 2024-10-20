// this is a test, 
// i'm experimenting, i'm trying to do something similar that the MCPE decompiler devs did with APP thing
//
//
#pragma once

#include "Minecraft.h"
#include "World/map/MapColor.h"
#include "World/Block/Material/Material.h"
#include "World/Block/Block.h"
#include "Network/Packet.h"
#include "Java/Math/Random.h"

// Test
#include "Timer.h"


class Game
{
public:
    Game();
    ~Game();
    
    unsigned long long currentTimeMills();
	void init(Minecraft* mc);
    void run(Minecraft* mc);
	void shutdown();

private:
    bool staticCtorsInitialized;
};