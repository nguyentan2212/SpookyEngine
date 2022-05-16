#pragma once
#include "Core/Scene.h"
#include "Character.h"
#include "ChowmeinConga.h"

class CustomScene : public Scene
{
public:
	CustomScene();

	bool Initialize(Matrix coordinateMatrix);
};

