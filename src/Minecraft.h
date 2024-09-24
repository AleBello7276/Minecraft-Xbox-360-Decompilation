#pragma once

#include <xtl.h>
#include <xboxmath.h>
#include <cstdio>
#include "World/entity/Entity.h"
#include "Logger.h"
#include "DefaultShaders.h"


class Minecraft {

// Sample Structs
private: 
    struct COLORVERTEX
    {
        float       Position[3];
        DWORD       Color;
    };

    struct TimeInfo
    {    
        LARGE_INTEGER qwTime;    
        LARGE_INTEGER qwAppTime;   

        float fAppTime;    
        float fElapsedTime;    

        float fSecsPerTick;    
    };

public:
    Minecraft();
    ~Minecraft();

    void init();
    void run();

    


private:
    D3DDevice*             g_pd3dDevice;    // Our rendering device
    D3DVertexBuffer*       g_pVB;           // Buffer to hold vertices
    D3DVertexDeclaration*  g_pVertexDecl;   // Vertex format decl
    D3DVertexShader*       g_pVertexShader; // Vertex Shader
    D3DPixelShader*        g_pPixelShader;  // Pixel Shader

    XMMATRIX g_matWorld;
    XMMATRIX g_matProj;
    XMMATRIX g_matView;

    TimeInfo g_Time;

    BOOL g_bWidescreen;

    //Testing
    Entity* e;


    // Xdk sample
    void InitTime();
    HRESULT InitD3D();
    HRESULT InitScene();
    void UpdateTime();
    void Update();
    void Render();
    void initSample();
    void runSample();

    
};