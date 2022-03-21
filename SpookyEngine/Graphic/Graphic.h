#pragma once
#include<d3d9.h>
#include<d3dx9.h>
#include <unordered_map>
#include <memory>
#include <vector>
#include "Texture.h"
#include "Sprite.h"
#include "../Core/GameObject.h"
#include "../Core/Camera2D.h"
#include "../Core/Scene.h"

using namespace::std;

class Graphic
{
public:
	~Graphic();
	bool Initialize(HWND hWnd, int width, int height);
	void UpdateScene(double delta);
	void Render();

	shared_ptr<Texture> GetTexture(string name) {
		return textures[name];
	}

	shared_ptr<Sprite> GetSprite(shared_ptr<Texture> texture, double width, double height, double x, double y, bool isFlipped = false);

protected:
	LPDIRECT3D9 d3d;            // the pointer to our Direct3D interface
	LPDIRECT3DDEVICE9 d3ddev;   // the pointer to the device class
	LPDIRECT3DSURFACE9	backBuffer; // back buffer

	int windowWidth = 0;
	int windowHeight = 0;
	
	vector<shared_ptr<Scene>> scenes;
	shared_ptr<Scene> currentScene;
	shared_ptr<Camera2D> cam;

	LPD3DXSPRITE spriteHandler;
	unordered_map<string, shared_ptr<Texture>> textures;

	bool InitializeDirectX(HWND hWnd);

	// virtual func
	virtual bool InitializeTexture() = 0;
	virtual bool InitializeScene() = 0;
};

