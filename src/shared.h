#include "xbox_intellisense_platform.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <xtl.h>
#include <d3d9.h>
#include <d3dx9.h>
#include <XAudio2.h>
#include <Xui.h>


extern BOOL g_isWideScreen;
extern D3DDevice* g_d3dDevice;
extern IXAudio2* g_xAudio2;
extern IXAudio2MasteringVoice* g_masterVoice;