#pragma once
#include <memory>
#include <vector>
#include "Frame.h"
#include "../Math/Transform2D.h"
#include "../Utils/StringConverter.h"
#include <d3d9.h>

using namespace::std;

class Animation : public Drawable2D
{
public:
	Animation();

	void AddFrame(shared_ptr<Frame> frame);
	void AddFrame(shared_ptr<Sprite> sprite, int frameTime);
	void AddFrame(vector<shared_ptr<Sprite>> sprites, int frameTime);

	void Update(double delta);
	void Render(Matrix transMat);
	void SetZIndex(float zIndex);

	void SetPosition(Vector vec) {
		transform.SetPosition(vec);
	}

private:
	vector<shared_ptr<Frame>> frames;
	int currentFrame;
	double aniTime;
	Transform2D transform;
};

