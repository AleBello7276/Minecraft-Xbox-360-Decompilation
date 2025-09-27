#include "CMinecraftApp.h"

CXboxMinecraftApp g_XMcApp;



//
// TU2 .text 0x824eb558
// this is not exactly matching, it is optimized away in TU2
// so i'll reimplement based on the usage
// it is used sometime to print error messages
//
void CMinecraftApp::DebugPrintf(char* fmt, ...) 
{
	va_list args;
	va_start(args, fmt);
	vprintf(fmt, args);
	va_end(args);
}

//
// TU2 .text 8228caf8
//
HRESULT CMinecraftApp::InitialiseXui()
{
	HRESULT hr;
	XUIInitParams xip;

	
	if (this->isInit)
	{
		if (this->m_XDC == NULL) {
			hr = XuiRenderCreateDC(&this->m_XDC);
			if (FAILED(hr)) {
				return hr;
			}
		}

		XUI_INIT_PARAMS(xip);
		hr = XuiInit(&xip);
		if (FAILED(hr)) {
			hr = XuiRenderDestroyDC(this->m_XDC);
			this->m_XDC = NULL;
			return hr;
		}
	}

	this->unk3 = true;
}


// TU2 .text 0x8228a7c0
CMinecraftApp::CMinecraftApp() {
	QueryPerformanceFrequency(&this->PerfFreq);
	QueryPerformanceCounter(&this->PerfCount);
	this->pUnk1 = (void*)0x0;
	this->m_XDC = NULL;
	this->isInit = true;
	this->unk3 = 0;
	this->unk4 = 0;
	this->unk6 = 0;
	this->unk7 = 0;
	this->unk8 = 0;
}

// TU2 .text 8227ea28
CXboxMinecraftApp::CXboxMinecraftApp() {
	// TODO:

	
}


// TU2 .text 8227ed70
void CXboxMinecraftApp::RegisterXuiClasses()
{
	// TODO:
	// STUBBBBBBB
}
