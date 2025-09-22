
#include "Renderer.h"


struct C4JRender
{
	uint32_t unk0[8];
	Renderer renderer;

	
	// TU2 .text 0x824e1770
	void Initialise(D3DDevice* d3dDevice)
	{
		this->renderer.Initialise(d3dDevice);
	}

};

