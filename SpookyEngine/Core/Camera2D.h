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
	void Initialize(double top, double left, double width, double height);
	void Update();

	void FollowObj(shared_ptr<GameObject> followedObj);
	void SetPosition(Vector pos) {
		position = Vector(pos);
	}
	Vector GetPosition() const {
		return position;
	}

private:
	Camera2D() {};
	double width = 0;
	double height = 0;
	Vector position;
	shared_ptr<GameObject> followedObj;
	static shared_ptr<Camera2D> instance;
};

