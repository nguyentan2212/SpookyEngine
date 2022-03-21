#pragma once
#include "Core/Scene.h"
#include "CustomGraphic.h"
#include "Character.h"

class CustomScene : public Scene
{
public:
	CustomScene() : Scene() {}

	bool Initialize();
};

