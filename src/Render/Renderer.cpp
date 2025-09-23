#include "Renderer.h"


uint32_t DAT_829bc16c = 0; // TU2 .data 0x829bc16c


#include "TU2Shaders.h"

static D3DVERTEXELEMENT9 elemVX0[] =
{
	{ 0, 0,	 D3DDECLTYPE_FLOAT3, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 12, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	{ 0, 20, D3DDECLTYPE_D3DCOLOR, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_COLOR, 0 },
	{ 0, 24, D3DDECLTYPE_BYTE4N, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_NORMAL, 0 },
	D3DDECL_END()
};
static D3DVERTEXELEMENT9 elemVX1[] =
{
	{ 0, 0,	 D3DDECLTYPE_SHORT4, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	D3DDECL_END()
};
static D3DVERTEXELEMENT9 elemVX2[] =
{
	{ 0, 0,	 D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_POSITION, 0 },
	{ 0, 8, D3DDECLTYPE_FLOAT2, D3DDECLMETHOD_DEFAULT, D3DDECLUSAGE_TEXCOORD, 0 },
	D3DDECL_END()
};

// TU2 .data 8297d7a4
static const char* tu2Shaders[6] = { shaderCode0, shaderCode1, shaderCode2, shaderCode3, shaderCode4, shaderCode5 };

// TU2 .data 82042a20
static DWORD g_vxStreamStrides[3] = { 0x20, 0x8, 0x20 };

// TU2 .data 8297d798
// vertexElements
static D3DVERTEXELEMENT9* g_vxElements[3] = { elemVX0, elemVX1, elemVX2 };





// TU2 .text 0x824e44d0
void Renderer::Initialise(D3DDevice* d3dDevice)
{
	m_d3dDevice = d3dDevice;
	this->CreateCommandBuffer();

	// TODO: Figure out what these arrays are 
	this->unk1 = (void*)(new uint8_t(0x7d000));
	this->unk2 = (void*)(new uint8_t(32000));
	this->unk3 = (void*)(new uint8_t(32000));
	this->unk4 = (void*)(new uint8_t(0x7d000));
	this->unk5 = (void*)(new uint8_t(32000));
	this->unk6 = (void*)(new uint8_t(8000));
	memset(this->unk1, 0xff, 0x7d000);
	memset(this->unk2, 0, 32000);
	memset(this->unk3, 0, 32000);
	memset(this->unk5, 0, 32000);
	memset(this->unk6, 0, 8000);
	this->unk7 = 0;
	this->unk8 = 0;

	SetupShaders();
}


// TU2 .text 824e43b0
void CreateBufferedDevice(uint8_t* param_1, D3DDevice* device)
{
	// TODO make it pretty :}

	param_1[0x10c4] = '\0';
	param_1[0x10c5] = '\0';
	param_1[0x10c6] = '\0';
	param_1[0x10c7] = '\0';
	param_1[0x10c8] = '\0';
	param_1[0x10c9] = '\0';
	param_1[0x10ca] = '\0';
	param_1[0x10cb] = '\0';
	param_1[0x10cc] = '\0';
	param_1[0x10cd] = '\0';
	param_1[0x10ce] = '\0';
	param_1[0x10cf] = '\0';

	Direct3D::CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE::D3DDEVTYPE_COMMAND_BUFFER, NULL, 0, NULL, (D3DDevice**)(*(param_1 + 0x1028)));


	// TODO: finish this
}

// TU2 .text 0x824e4478
void Renderer::CreateCommandBuffer()
{
	uint8_t* uVar1 = new uint8_t(0x10e0);
	if (uVar1)
	{
		CreateBufferedDevice(uVar1, this->m_d3dDevice);
	}

	TlsSetValue(DAT_829bc16c, uVar1);
}





// TU2 .text 824e3608
void Renderer::SetupShaders()
{
	this->m_vxShaderSrcs = new char * [3];
	this->m_vxShaderHandles = new D3DVertexShader * [3];


	uint32_t idx = 0;
	while (true) 
	{
		this->m_vxShaderSrcs[idx] = (char*)tu2Shaders[idx];

		char* curShaderCode = (char*)tu2Shaders[idx];
		size_t codeLen = strlen(curShaderCode);
		
		LPD3DXBUFFER compiledShader = NULL;
		HRESULT hr = D3DXCompileShader(
			curShaderCode,
			codeLen,
			NULL, NULL,
			"main", "vs.2.0", NULL,
			&compiledShader, NULL, NULL
		);
		if (FAILED(hr)) break;

		// create vertex shader 0x824e36e4
		DWORD* func = (DWORD*)compiledShader->GetBufferPointer();
		m_vxShaderHandles[idx] = D3DDevice_CreateVertexShader(func);
		
		D3DVertexDeclaration* decl = D3DDevice_CreateVertexDeclaration(g_vxElements[idx]);
		m_vxShaderHandles[idx]->Bind(NULL, decl, &g_vxStreamStrides[idx], NULL);

		decl->Release();
		compiledShader->Release();

		idx++;
		compiledShader = NULL;

		// TODO:
		// Funny magic numbers ;p
		if (idx == 3)
		{

			// px shader index 3
			curShaderCode = (char*)tu2Shaders[3];
			codeLen = strlen(curShaderCode);
			hr = D3DXCompileShader(
				curShaderCode, 
				codeLen, 
				NULL, 
				NULL, 
				"main", "ps.2.0", NULL, 
				&compiledShader, NULL, NULL);
			// TODO: make it match 
			if (FAILED(hr)) {
				printf("SetupShaders: Failed compiling pixel shader 3\n");
				exit(1);
			}
			func = (DWORD*)compiledShader->GetBufferPointer();
			m_pxShader_0x48 = D3DDevice_CreatePixelShader(func);
			compiledShader->Release();
			

			// vs shader index 4
			compiledShader = NULL;
			curShaderCode = (char*)tu2Shaders[4];
			codeLen = strlen(curShaderCode);
			hr = D3DXCompileShader(
				curShaderCode,
				codeLen,
				NULL,
				NULL,
				"main", "vs.2.0", NULL,
				&compiledShader, NULL, NULL);
			// TODO: make it match 
			if (FAILED(hr)) {
				printf("SetupShaders: Failed compiling vertex shader 4\n");
				exit(1);
			}
			func = (DWORD*)compiledShader->GetBufferPointer();
			m_vxShader_0x44 = D3DDevice_CreateVertexShader(func);
			//
			// it uses elemVX2 cause the layout is the same i guess
			//
			D3DVertexDeclaration* decl = D3DDevice_CreateVertexDeclaration(elemVX2);
			DWORD stride = 0x10;
			m_vxShaderHandles[idx]->Bind(NULL, decl, &stride, NULL);
			decl->Release();
			compiledShader->Release();

			
			// px shader index 5
			compiledShader = NULL;
			curShaderCode = (char*)tu2Shaders[5];
			codeLen = strlen(curShaderCode);
			hr = D3DXCompileShader(
				curShaderCode,
				codeLen,
				NULL,
				NULL,
				"main", "ps.2.0", NULL,
				&compiledShader, NULL, NULL);
			// TODO: make it match 
			if (FAILED(hr)) {
				printf("SetupShaders: Failed compiling pixel shader 5\n");
				exit(1);
			}
			func = (DWORD*)compiledShader->GetBufferPointer();
			m_pxShader_0x4c = D3DDevice_CreatePixelShader(func);
			compiledShader->Release();
			
			
			return;
		}
	}


	printf("SetupShaders: Something is wrong, how did you got here\n");
	exit(1);
}
