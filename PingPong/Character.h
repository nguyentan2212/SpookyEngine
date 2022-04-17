#pragma once

#include "Core/GameObject.h"
#include "Keyboard/KeyboardClass.h"

#define LEFT -1
#define RIGHT 1

using namespace::std;

class Character : public GameObject
{
public: 
	Character() : GameObject() {}
	Character(const Vector& position) : GameObject(position) {}
	Character(const Transform2D& transform) : GameObject(transform) {}

	void Initialize();
	void Update(double delta);

private: 
	int state = RIGHT;
};

