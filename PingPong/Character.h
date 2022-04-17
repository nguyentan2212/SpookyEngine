#pragma once

#include <string>
#include "Core/GameObject.h"
#include "Keyboard/KeyboardClass.h"
#include "Core/ResourceLocator.h"
#include "Utils/StringConverter.h"

#define LEFT -1
#define RIGHT 1

using namespace::std;

class Character : public GameObject
{
public: 
	Character(string name, double width, double height, Vector pos);

	void Initialize();
	void Update(double delta);
	void Render(Matrix transMat);
	void OnCollision(vector<CollisionEvent> collisionEvents);

private: 
	int state = RIGHT;
};

