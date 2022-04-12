#include "Frame.h"

Frame::Frame(shared_ptr<Sprite> sprite, int frameTime) : Drawable2D()
{
	this->sprites = vector<shared_ptr<Sprite>>(0);
	this->sprites.push_back(sprite);
	this->frameTime = frameTime;
}

Frame::Frame(vector<shared_ptr<Sprite>> sprites, int frameTime) : Drawable2D()
{
	this->sprites = sprites;
	this->frameTime = frameTime;
}

void Frame::Render(Matrix transMat)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->Render(transMat * transform.GetLocalTransform());
	}
}

void Frame::SetZIndex(float zIndex)
{
	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->SetZIndex(zIndex);
	}
}
