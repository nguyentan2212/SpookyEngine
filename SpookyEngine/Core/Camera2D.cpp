#include "Camera2D.h"

shared_ptr<Camera2D> Camera2D::instance = nullptr;

void Camera2D::Initialize(long bottom, long left, long width, long height)
{
	position = Vector(left, bottom);
	this->width = width;
	this->height = height;
}

void Camera2D::Update()
{
	if (followedObj == nullptr)
	{
		return;
	}

	Vector center = position + Vector(width / 2, height / 2);
	Vector trans = followedObj->GetLocalPosition() - center;
	Vector temp = position + trans;

	double x = 0;
	double y = 0;
	if (temp.GetValueX() > 0)
	{
		x = temp.GetValueX();
	}
	if (temp.GetValueY() > 0)
	{
		y = temp.GetValueY();
	}

	position = Vector(x, y);
	// OutputDebugStringW((L"[Sprite]: " + to_wstring(position.GetValueX()) + L", " + to_wstring(position.GetValueY()) + L"\n").c_str());
}

void Camera2D::FollowObj(shared_ptr<GameObject> followedObj)
{
	this->followedObj = followedObj;
}

shared_ptr<Camera2D> Camera2D::GetInstance()
{
	if (instance == nullptr)
	{
		instance = shared_ptr<Camera2D>(new Camera2D());
	}
	return instance;
}
