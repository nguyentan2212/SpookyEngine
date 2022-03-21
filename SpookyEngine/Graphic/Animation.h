#pragma once
#include <memory>
#include <vector>
#include "Sprite.h"

using namespace::std;

class Frame {
public:
	Frame(shared_ptr<Sprite> sprite, int frameTime) {
		this->sprite = sprite;
		this->frameTime = frameTime;
	}

private:

	shared_ptr<Sprite> sprite;
	int frameTime;
	friend class Animation;
};

class Animation
{
public:
	Animation();

	void AddFrame(shared_ptr<Sprite> sprite, int frameTime);

	void Update(double delta);
	void Render(Matrix3D transMat, Vector3D camPos);

private:
	vector<shared_ptr<Frame>> frames;
	int currentFrame;
};

