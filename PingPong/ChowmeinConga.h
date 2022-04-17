#pragma once
#include <string>
#include "Core/GameObject.h"
#include "Core/ResourceLocator.h"

using namespace::std;

#define LEFT -1
#define RIGHT 1

class ChowmeinConga : public GameObject
{
public:
	ChowmeinConga(string name, double width, double height, Vector pos);

	void Initialize();
	void Update(double delta);
	void Render(Matrix transMat);

private:
	int state = RIGHT;
};

