
#include "../shared.h"


struct Renderer
{
	D3DDevice* m_d3dDevice;
	void* unk1;
	void* unk2;
	void* unk3;
	void* unk4;
	void* unk5;
	void* unk6;
	uint32_t unk7;
	uint32_t unk8;
	uint32_t criticalSection;
	uint32_t gap6[6];

	D3DPixelShader* pxShaders[3];
	uint32_t unk_4c;
	D3DVertexShader* vxShaders[3];

	void Initialise(D3DDevice* d3dDevice);
	void CreateCommandBuffer();
	void SetupShaders();
};


