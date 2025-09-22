
#include "shared.h"


BOOL g_isWideScreen = true;

D3DDevice* g_d3dDevice = nullptr;

HXUIDC* g_xuiDC = nullptr;

//
// 0x8228b5d8
//
HRESULT InitD3DDevice(D3DDevice* outDevice, D3DPRESENT_PARAMETERS* params)
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

	return Direct3D::CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE::D3DDEVTYPE_HAL, nullptr, D3DCREATE_BUFFER_2_FRAMES, params, &outDevice);
}

int main() 
{
	D3DPRESENT_PARAMETERS d3dpp;
	D3DDevice* d3Dev;
	HRESULT hr;
	char* failString;

	hr = InitD3DDevice(d3Dev, &d3dpp);
	g_d3dDevice = d3Dev;

	if (FAILED(hr)) {
		failString = "Failed initializing D3D.\n";
	}
	else
	{
		hr = XuiRenderInitShared(d3Dev, &d3dpp, XuiPNGTextureLoader);
		if (SUCCEEDED(hr)) 
		{
			hr = XuiRenderCreateDC(g_xuiDC);
			if (SUCCEEDED(hr))
			{
				
			}

			// TODO: Verify if this is correct
			XuiRenderDestroyDC(*g_xuiDC);
		}

		failString = "Failed initializing application.\n";
	}
	
	return 0;
}