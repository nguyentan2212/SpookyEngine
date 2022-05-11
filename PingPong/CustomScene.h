#pragma once
#include "Core/Scene.h"
#include "Character.h"
#include "ChowmeinConga.h"
#include "Lotust.h"

class CustomScene : public Scene
{
public:
	CustomScene();

	bool Initialize(Matrix coordinateMatrix);
};

