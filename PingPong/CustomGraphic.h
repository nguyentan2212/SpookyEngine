#pragma once
#include "Graphic/Graphic.h"
#include "CustomScene.h"
#include "CustomCamera.h"

class CustomGraphic : public Graphic
{
public:
	CustomGraphic(CustomGraphic&) = delete;
	void operator=(CustomGraphic&) = delete;
	static shared_ptr<CustomGraphic> GetInstance();
protected:
	bool InitializeTexture();
	bool InitializeScene();
	static shared_ptr<CustomGraphic> instance;
	CustomGraphic();
};

