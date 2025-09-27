
#include "shared.h"
#include "Render/C4JRender.h"
#include "CMinecraftApp.h"




BOOL g_isWideScreen = true;
D3DDevice* g_d3dDevice = nullptr;
IXAudio2* g_xAudio2 = nullptr;
IXAudio2MasteringVoice* g_masterVoice = nullptr;






//
// TU2 .text 0x8228b5d8
//
HRESULT InitD3DDevice(D3DDevice** outDevice, D3DPRESENT_PARAMETERS* params)
{
	// to be accurate TU2 doesen't initialize it to zero, but let's be good programmers :)
	XVIDEO_MODE VideoMode = { 0 };

	memset(params, 0, sizeof(D3DPRESENT_PARAMETERS));
	XGetVideoMode(&VideoMode);
	params->BackBufferCount = 1;
	params->BackBufferWidth = 1280;
	params->BackBufferHeight = 720;
	params->BackBufferFormat = D3DFORMAT::D3DFMT_A8R8G8B8;
	params->EnableAutoDepthStencil = 1;
	params->AutoDepthStencilFormat = D3DFORMAT::D3DFMT_D24S8;
	params->SwapEffect = D3DSWAPEFFECT_DISCARD;
	params->PresentationInterval = D3DPRESENT_INTERVAL_ONE;
	g_isWideScreen = VideoMode.fIsWideScreen;
	params->Flags = (VideoMode.fIsWideScreen == 0);

	return Direct3D::CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE::D3DDEVTYPE_HAL, NULL, D3DCREATE_BUFFER_2_FRAMES, params, outDevice);
}


// TU2 .text 0x8228b6a0
int main() 
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDevice* d3Dev;
	HRESULT hr;
	char* failString;

	hr = InitD3DDevice(&d3Dev, &d3dpp);
	g_d3dDevice = d3Dev;

	printf("InitD3DDevice hr = 0x%08x\n", d3Dev);	

	if (FAILED(hr)) {
		failString = "Failed initializing D3D.\n";
	}
	else
	{

		hr = XuiRenderInitShared(d3Dev, &d3dpp, *XuiPNGTextureLoader);
		
		if (SUCCEEDED(hr)) 
		{
			g_XMcApp.DebugPrintf("pre XUI");

			hr = g_XMcApp.InitialiseXui();
			g_XMcApp.DebugPrintf("post XUI %d", hr);

			if (SUCCEEDED(hr))
			{
				//0x8228b770
				g_FJRender.Initialise(d3Dev);

				// XAudio2 actually seams not to be used in TU2, *i think*, idk why
				// in fact the game uses XACT
				hr = XAudio2Create(&g_xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
				if (FAILED(hr)) {
					failString = "Failed initializing D3D.\n";
					g_XMcApp.DebugPrintf("Initializing XAudio2 failed (err = 0x%08x)!\n", hr);
					
					// TODO: 8228b7a8 Print_MC_Res_ERROR
				}

				g_xAudio2->CreateMasteringVoice(&g_masterVoice, XAUDIO2_DEFAULT_CHANNELS, XAUDIO2_DEFAULT_SAMPLERATE, 0, 0, NULL);
			}


		}

		failString = "Failed initializing application.\n";
	}
	

	if (failString) {
		g_XMcApp.DebugPrintf(failString);
	}

	return 0;
}