#pragma once
#include <memory>
#include <vector>
#include "Sprite.h"

using namespace::std;

class Frame : public Drawable2D
{
public:
	Frame(shared_ptr<Sprite> sprite, int frameTime);
	Frame(vector<shared_ptr<Sprite>> sprites, int frameTime);

	void Render(Matrix transMat);
	void SetZIndex(float zIndex);

private:
	vector<shared_ptr<Sprite>> sprites;
	int frameTime;
	friend class Animation;
};