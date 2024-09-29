// this is a test, 
// i'm experimenting, i'm trying to do something similar that the MCPE decompiler devs did with APP thing
//
//
#include "Game.h"


Game::Game() {}

Game::~Game()
{

}

void Game::init(Minecraft* mc)
{

    if(this->staticCtorsInitialized == false)
    {
        // minecraft staticCtors
        this->staticCtorsInitialized = true;
        MapColor::statiCtor();
        Material::statiCtor();
        Block::staticCtor();
    }

    // after everything is done call the minecraft init
    mc->init();
}

void Game::run(Minecraft* mc) 
{
    mc->run();
}



void Game::shutdown()
{
    //Nothing for now
}

unsigned long long Game::currentTimeMills()
{
    SYSTEMTIME systemTime; 
    FILETIME fileTime;
    unsigned long long  fileTimeIn64;

    GetSystemTime(&systemTime); // 0x826b2f58
    SystemTimeToFileTime(&systemTime, &fileTime); // 0x822be100
    
    fileTimeIn64 = ((unsigned long long )fileTime.dwHighDateTime << 32) | fileTime.dwLowDateTime; 

    // from 100-nanosecond intervals to milliseconds i guess !?!?
    return fileTimeIn64 / 10000;
}

int __cdecl main()
{
    Game* game = new Game();
    // mc instance
    Minecraft* mc = new Minecraft();
   

    game->init(mc);
     unsigned long long startTime = game->currentTimeMills();

    for(;;) // loop forever
    {
        game->run(mc);
        //Logger::LogPrintf("-------------TEST %i------------------",  time - startTime);
        if(game->currentTimeMills() >= startTime + 1000)
        {
            mc->timer->updateTimer();
            startTime += 1000;
        }
        Logger::LogPrintf("-------------TEST %i------------------",  mc->timer->elapsedTicks);
    }

    //delete mc;
    delete game;

    return 0;
}