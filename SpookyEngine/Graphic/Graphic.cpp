#include "Graphic.h"

shared_ptr<Graphic> Graphic::instance = nullptr;

Graphic::~Graphic()
{
	d3d->Release(); 
	d3ddev->Release();
	backBuffer->Release();
	spriteHandler->Release();
	if (g_pVB != nullptr) {
		g_pVB->Release();
	}
	if (g_pIB != nullptr) {
		g_pIB->Release();
	}
}

shared_ptr<Graphic> Graphic::GetInstance()
{
	if (instance == nullptr)
	{
		instance = shared_ptr<Graphic>(new Graphic());
	}
	return instance;
}

bool Graphic::Initialize(HWND hWnd, int width, int height)
{
	g_pVB = NULL;

	windowWidth = width;
	windowHeight = height;

	if (!InitializeDirectX(hWnd)) 
	{
		return false;
	}

	return true;
}

bool Graphic::InitializeDirectX(HWND hWnd)
{
	d3d = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));    		// clear out the struct for use // fill null
	d3dpp.Windowed = TRUE;    					// program windowed, not fullscreen
	d3dpp.hDeviceWindow = hWnd;    				// set the window to be used by Direct3D

	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;   // discard old frames
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferHeight = windowHeight;
	d3dpp.BackBufferWidth = windowWidth;

	// create a device class using this information and the info from the d3dpp stuct
	HRESULT hr = d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	hr = d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);
	D3DXCreateSprite(d3ddev, &spriteHandler);

	return true;
}

void Graphic::BeginRender()
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0);

	d3ddev->BeginScene();
}

void Graphic::EndRender()
{
	// DrawBox(50, 50, 80, 80);
	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);
}

void Graphic::BeginSprite()
{
	spriteHandler->Begin(D3DXSPRITE_SORT_DEPTH_FRONTTOBACK | D3DXSPRITE_ALPHABLEND);
}

void Graphic::EndSprite()
{
	spriteHandler->End();
}

void Graphic::DrawBoxFilled(float x, float y, float w, float h, DWORD color)
{
	vertex V[4];

	V[0].color = V[1].color = V[2].color = V[3].color = color;

	V[0].z = V[1].z = V[2].z = V[3].z = 1.0f;
	V[0].rhw = V[1].rhw = V[2].rhw = V[3].rhw = 1.0f;

	V[0].x = x;
	V[0].y = y;
	V[1].x = x + w;
	V[1].y = y;
	V[2].x = x + w;
	V[2].y = y + h;
	V[3].x = x;
	V[3].y = y + h;

	unsigned short indexes[] = { 0, 1, 3, 1, 2, 3 };

	d3ddev->CreateVertexBuffer(4 * sizeof(vertex), 0, D3DFVF_XYZRHW | D3DFVF_DIFFUSE, D3DPOOL_MANAGED, &g_pVB, NULL);
	d3ddev->CreateIndexBuffer(6 * sizeof(short), 0, D3DFMT_INDEX16, D3DPOOL_MANAGED, &g_pIB, NULL);

	VOID* pVertices;
	g_pVB->Lock(0, sizeof(V), (void**)&pVertices, 0);
	memcpy(pVertices, V, sizeof(V));
	g_pVB->Unlock();

	VOID* pIndex;
	g_pIB->Lock(0, sizeof(indexes), (void**)&pIndex, 0);
	memcpy(pIndex, indexes, sizeof(indexes));
	g_pIB->Unlock();

	d3ddev->SetStreamSource(0, g_pVB, 0, sizeof(vertex));
	d3ddev->SetFVF(D3DFVF_XYZRHW | D3DFVF_DIFFUSE);
	d3ddev->SetIndices(g_pIB);

	d3ddev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

void Graphic::DrawBox(float x, float y, float w, float h, DWORD color)
{
	x -= w / 2;
	y -= h / 2;

	DrawBoxFilled(x, y, w, 1, color);             // Top
	DrawBoxFilled(x, y + h - 1, w, 1, color);         // Bottom
	DrawBoxFilled(x, y + 1, 1, h - 2 * 1, color);       // Left
	DrawBoxFilled(x + w - 1, y + 1, 1, h - 2 * 1, color);   // Right
}

void Graphic::Draw(shared_ptr<SpriteInfo> info, RECT srcRect ,Vector center, Vector position, D3DXMATRIX transformMatrix)
{
	spriteHandler->SetTransform(&transformMatrix);

	D3DXVECTOR3 pCenter = center.ToDirectXVector();
	D3DXVECTOR3 pPos = position.ToDirectXVector();
	spriteHandler->Draw(info->texture->GetTexture(), &srcRect, &pCenter, &pPos, D3DCOLOR_XRGB(255, 255, 255));
}
