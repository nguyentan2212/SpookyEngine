#pragma once
#include <d3d9.h>
#include <string>
#include <d3dx9.h>
#include <comdef.h>
#include "../Utils/StringConverter.h"

using namespace::std;

class Texture
{
public:
	Texture(LPDIRECT3DDEVICE9 d3ddev, LPCWSTR filePath, D3DCOLOR transparentColor = NULL);
	LPDIRECT3DTEXTURE9 GetTexture() const {
		return texture;
	}

	D3DCOLOR GetTransparentColor() const {
		return transparentColor;
	}

private:
	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXIMAGE_INFO info;
	D3DCOLOR transparentColor;
};

