#pragma once
#include <memory>
#include "Texture.h"
#include "../Math/Transform2D.h"

class Sprite : public Transform2D
{
public:
	Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, RECT srcRect);
	Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, double width, double height, double x, double y);

	void Render(Matrix3D transMat, Vector3D camPos);

	double GetWidth() const {
		return srcRect.right - srcRect.left;
	}
	double GetHeight() const {
		return srcRect.bottom - srcRect.top;
	}
	std::shared_ptr<Texture> GetTexture() const {
		return texture;
	}

private:
	std::shared_ptr<Texture> texture; 
	RECT srcRect;
	LPD3DXSPRITE spriteHandler;
};

