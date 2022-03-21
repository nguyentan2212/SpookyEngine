﻿#include "Graphic.h"

Graphic::~Graphic()
{
	d3d->Release(); 
	d3ddev->Release();
	backBuffer->Release();
	spriteHandler->Release();
}

bool Graphic::Initialize(HWND hWnd, int width, int height)
{
	windowWidth = width;
	windowHeight = height;

	if (!InitializeDirectX(hWnd)) 
	{
		return false;
	}

	if (!InitializeTexture())
	{
		return false;
	}

	if (!InitializeScene() || currentScene == nullptr || cam == nullptr)
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
	d3d->CreateDevice(D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&d3ddev);

	d3ddev->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backBuffer);

	D3DXCreateSprite(d3ddev, &spriteHandler);

	return true;
}

void Graphic::UpdateScene(double delta)
{
	currentScene->Update(delta);
	cam->Update(delta);
}

void Graphic::Render()
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 40, 100), 1.0f, 0);
	
	d3ddev->BeginScene();

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	currentScene->Render(cam->GetLocalPosition());

	spriteHandler->End();

	d3ddev->EndScene();

	d3ddev->Present(NULL, NULL, NULL, NULL);
}

shared_ptr<Sprite> Graphic::GetSprite(shared_ptr<Texture> texture, double width, double height, double x, double y, bool isFlipped)
{
	return shared_ptr<Sprite>(new Sprite(texture, spriteHandler, width, height, x, y, isFlipped));
}
