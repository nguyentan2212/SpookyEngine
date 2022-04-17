#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <memory>
#include <queue>
#include "Drawable2D.h"
#include "Sprite.h"
 
using namespace::std;

#define SCALE 1.5f

struct vertex
{
	FLOAT x, y, z, rhw;
	DWORD color;
};

class Sprite;
struct SpriteInfo;

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
	void BeginSprite();
	void EndSprite();

	double GetScaleFactor() const {
		return 1.0f;
	}

	LPDIRECT3DDEVICE9 GetDevice() const {
		return d3ddev;
	}

	void DrawBoxFilled(float x, float y, float w, float h, DWORD color = D3DCOLOR_XRGB(255, 0, 0));
	void DrawBox(float x, float y, float w, float h, DWORD color = D3DCOLOR_XRGB(255, 0, 0));
	void Draw(shared_ptr<SpriteInfo> info, RECT srcRect, Vector center, Vector position, D3DXMATRIX transformMatrix);

protected:
	LPDIRECT3D9 d3d;            // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;   // the pointer to the device class
	LPDIRECT3DSURFACE9	backBuffer; // back buffer
	LPDIRECT3DVERTEXBUFFER9 g_pVB;    // Buffer to hold vertices
	LPDIRECT3DINDEXBUFFER9  g_pIB;    // Buffer to hold indices
	LPD3DXSPRITE spriteHandler;

	int windowWidth = 0;
	int windowHeight = 0;
	priority_queue<Drawable2D> renderQueue;
	bool InitializeDirectX(HWND hWnd);

	Graphic(){}
	static shared_ptr<Graphic> instance;
};

