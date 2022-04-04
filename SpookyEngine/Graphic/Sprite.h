#pragma once
#include <memory>
#include <string>
#include "Texture.h"
#include "Drawable2D.h"
#include "../Math/Transform2D.h"

using namespace::std;

class Sprite : public Drawable2D
{
public:
	Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, RECT srcRect, bool isFlipped = false);
	Sprite(std::shared_ptr<Texture> texture, LPD3DXSPRITE spriteHandler, double width, double height, double x, double y, bool isFlipped = false);

	void Render(Matrix transMat);

	double GetWidth() const {
		return srcRect.right - srcRect.left;
	}
	double GetHeight() const {
		return srcRect.bottom - srcRect.top;
	}
	std::shared_ptr<Texture> GetTexture() const {
		return texture;
	}

	bool isFlipped;
private:
	std::shared_ptr<Texture> texture; 
	RECT srcRect;
	LPD3DXSPRITE spriteHandler;
};

