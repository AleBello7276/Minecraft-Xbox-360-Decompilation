
#include "shared.h"


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

	D3DVertexShader** m_vxShaderHandles;
	D3DVertexShader* m_vxShader_0x44;
	D3DPixelShader* m_pxShader_0x48;
	D3DPixelShader* m_pxShader_0x4c;
	char** m_vxShaderSrcs;

	void Initialise(D3DDevice* d3dDevice);
	void CreateCommandBuffer();
	void SetupShaders();
};


