#pragma once
#include "Core/GameObject.h"
#include "Keyboard/KeyboardClass.h"

#define LEFT -1
#define RIGHT 1

class Character : public GameObject
{
public: 
	Character() : GameObject() {}
	Character(const Vector3D& position) : GameObject(position) {}
	Character(const Transform2D& transform) : GameObject(transform) {}

	void Initialize();
	void Update(double delta);
	void Render(Vector3D camPos);

private: 
	int state = RIGHT;
};

