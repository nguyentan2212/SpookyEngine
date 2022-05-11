#pragma once

#include <string>
#include "Core/GameObject.h"
#include "Keyboard/KeyboardClass.h"
#include "Core/ResourceLocator.h"
#include "Utils/StringConverter.h"

using namespace::std;

class Character : public GameObject
{
public: 
	Character(string name, double width, double height, Vector pos);

	void Initialize();
	void Update(double delta);
	void Render(Matrix transMat);

private: 
	int state = RIGHT;
};

