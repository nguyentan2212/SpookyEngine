#pragma once
#include<d3d9.h>
#include <memory>
#include "GameObject.h"

using namespace::std;

class Camera2D
{
public:
	Camera2D(Camera2D&) = delete;
	void operator=(Camera2D&) = delete;
	static shared_ptr<Camera2D> GetInstance();
	void Initialize(long bottom, long left, long width, long height);
	void Update();

	void FollowObj(shared_ptr<GameObject> followedObj);
	void SetPosition(Vector pos) {
		position = Vector(pos);
	}
	Vector GetPosition() const {
		return position;
	}
	Vector GetSize() const {
		return Vector(width, height);
	}
private:
	Camera2D() {};
	long width = 0;
	long height = 0;
	Vector position;
	shared_ptr<GameObject> followedObj;
	static shared_ptr<Camera2D> instance;
};

