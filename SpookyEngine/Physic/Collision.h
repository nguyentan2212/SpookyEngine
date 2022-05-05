#pragma once
#include <memory>
#include <vector>
#include "../Math/Vector.h"
#include "../Core/GameObject.h"

#define LEFT 1
#define UP 2
#define RIGHT 3
#define DOWN 4

class Collision
{
public:
	static bool isColliding(BoundingBox obj, BoundingBox other);
	static double sweptAABB(BoundingBox obj, BoundingBox other, int& direction);

private:
	static BoundingBox getSweptBroadphaseBox(BoundingBox obj);
};

