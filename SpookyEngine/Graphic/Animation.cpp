#include "Animation.h"

Animation::Animation()
{
	frames = vector<shared_ptr<Frame>>(0);
	currentFrame = 0;
	aniTime = 0;
}

void Animation::AddFrame(shared_ptr<Sprite> sprite, int frameTime)
{
	shared_ptr<Frame> temp = shared_ptr<Frame>(new Frame(sprite, frameTime));
	frames.push_back(temp);
}

void Animation::Update(double delta)
{
	if (frames.size() <= 0)
	{
		return;
	}
	aniTime += delta;
	
	while (aniTime > frames[currentFrame]->frameTime)
	{
		aniTime = 0;
		currentFrame++;
		
		if (currentFrame == frames.size())
		{
			currentFrame = 0;
		}
	}
}

void Animation::Render(Matrix3D transMat, Vector3D camPos)
{
	if (frames.size() <= 0)
	{
		return;
	}
	OutputDebugStringW((L"[Animation]: " + to_wstring(currentFrame) + L"\n").c_str());
	if (currentFrame == 2) {
		
	}
	frames[currentFrame]->sprite->Render(transMat, camPos);
}
