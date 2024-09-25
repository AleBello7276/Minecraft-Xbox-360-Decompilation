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
        MapColor::initMapColors();
        Material::initMaterials();
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

int __cdecl main()
{
    Game* game = new Game();
    // mc instance
    Minecraft* mc = new Minecraft();


    game->init(mc);
    
    for(;;) // loop forever
    {
        Logger::LogPrintf("-------------MAIN LOOP------------------");
        game->run(mc);
    }

    //delete mc;
    delete game;

    return 0;
}