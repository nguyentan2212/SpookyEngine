#include "Animation.h"

Animation::Animation() : Drawable2D()
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

void Animation::AddFrame(vector<shared_ptr<Sprite>> sprites, int frameTime)
{
	shared_ptr<Frame> temp = shared_ptr<Frame>(new Frame(sprites, frameTime));
	frames.push_back(temp);
}

void Animation::AddFrame(shared_ptr<Frame> frame)
{
	frames.push_back(frame);
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

void Animation::Render(Matrix transMat)
{
	if (frames.size() <= 0)
	{
		return;
	}
	// OutputDebugStringW((L"[Animation]: " + to_wstring(currentFrame) + L"\n").c_str());
	if (currentFrame == 2) {
		
	}
	frames[currentFrame]->Render(transMat * transform.GetTransformMatrix());
}

void Animation::SetZIndex(float zIndex)
{
	for (int i = 0; i < frames.size(); i++)
	{
		frames[i]->SetZIndex(zIndex);
	}
}
