
#include "shared.h"
#include "Render/C4JRender.h"


BOOL g_isWideScreen = true;
D3DDevice* g_d3dDevice = nullptr;
IXAudio2* g_xAudio2 = nullptr;
HXUIDC* g_xuiDC = nullptr;

// 
//	.data addr 0x829baf68
//
C4JRender g_FJRender;



//
// TU2 .text 0x824eb558
// this is not exactly matching, it is optimized away in TU2
// so i'll reimplement based on the usage
// it is used sometime to print error messages
//
void print_error_thing(char* name, const char* message, ...)
{
	va_list args;
	va_start(args, message);
	vprintf(message, args);
	va_end(args);
	printf("\n %s: %s \n", name, message);
}


//
// TU2 .text 0x8228b5d8
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


// TU2 .text 0x8228b6a0
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
				//0x8228b770
				g_FJRender.Initialise(d3Dev);


				// XAudio2 actually seams not to be used in TU2, *i think*, idk why
				// in fact the game uses XACT
				hr = XAudio2Create(&g_xAudio2, 0, XAUDIO2_DEFAULT_PROCESSOR);
				if (FAILED(hr)) {
					failString = "Failed initializing D3D.\n";
				}
			}

			// TODO: Verify if this is correct
			XuiRenderDestroyDC(*g_xuiDC);
		}

		failString = "Failed initializing application.\n";
	}
	
	return 0;
}