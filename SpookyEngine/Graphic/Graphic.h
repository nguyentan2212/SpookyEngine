#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <memory>
#include <queue>
#include "../Core/Camera2D.h"
#include "Drawable2D.h"

using namespace::std;


class Graphic
{
public:
	Graphic(Graphic&) = delete;
	void operator=(Graphic&) = delete;
	~Graphic();
	static shared_ptr<Graphic> GetInstance();

	bool Initialize(HWND hWnd, int width, int height);
	void BeginRender();
	void EndRender();

	LPDIRECT3DDEVICE9 GetDevice() const {
		return d3ddev;
	}

	LPD3DXSPRITE GetSpriteHandler()  const {
		return spriteHandler;
	}

protected:
	LPDIRECT3D9 d3d;            // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;   // the pointer to the device class
	LPDIRECT3DSURFACE9	backBuffer; // back buffer
	LPD3DXSPRITE spriteHandler;

	int windowWidth = 0;
	int windowHeight = 0;
	priority_queue<Drawable2D> renderQueue;
	bool InitializeDirectX(HWND hWnd);

	Graphic(){}
	static shared_ptr<Graphic> instance;
};

