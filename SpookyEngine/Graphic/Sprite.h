#pragma once
#include <memory>
#include <string>
#include "Texture.h"
#include "Drawable2D.h"
#include "../Math/Transform2D.h"
#include "Graphic.h"

using namespace::std;

struct SpriteInfo {
	long x, y, width, height;
	shared_ptr<Texture> texture;
};

class Sprite : public Drawable2D
{
public:
	Sprite(shared_ptr<SpriteInfo> info, Vector scaleVec);
	Sprite(shared_ptr<SpriteInfo> info, double scaleX = 1, double scaleY = 1);

	void Render(Matrix transMat);
	void SetZIndex(float zIndex);

	shared_ptr<Texture> GetTexture() const {
		return info->texture;
	}

	RECT GetSrcRect() const 
	{
		RECT srcRect;
		srcRect.left = info->x;
		srcRect.top = info->y;
		srcRect.right = info->x + info->width;
		srcRect.bottom = info->y + info->height;
		return srcRect;
	}

	Vector GetCenter() const {
		return Vector(info->width / 2, info->height / 2, 0);
	}

	shared_ptr<SpriteInfo> GetInfo() const {
		return info;
	}

private:
	shared_ptr<SpriteInfo> info;
	Vector scaleVec;
};

