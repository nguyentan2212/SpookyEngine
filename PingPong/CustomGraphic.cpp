#include "CustomGraphic.h"

shared_ptr<CustomGraphic> CustomGraphic::instance = nullptr;

shared_ptr<CustomGraphic> CustomGraphic::GetInstance()
{
	if (instance == nullptr)
	{
		instance = shared_ptr<CustomGraphic>(new CustomGraphic());
	}
	return instance;
}

bool CustomGraphic::InitializeTexture()
{
	
	textures["background"] = shared_ptr<Texture>(new Texture(d3ddev, L"background/3.png", D3DCOLOR_XRGB(248, 0, 248)));
	for (int i = 0; i < 10; i++)
	{
		wstring str = L"characters/" + to_wstring(i) + L".png";
		textures["character" + to_string(i)] = shared_ptr<Texture>(new Texture(d3ddev, str.c_str(), D3DCOLOR_XRGB(247, 247, 247)));
	}
	

	return true;
}

bool CustomGraphic::InitializeScene()
{
	shared_ptr<CustomScene> scene = shared_ptr<CustomScene>(new CustomScene());
	if (!scene->Initialize())
	{
		return false;
	}
	scenes.push_back(scene);

	currentScene = scenes[0];

	cam = shared_ptr<CustomCamera>(new CustomCamera(0, 0, windowWidth, windowHeight, 5, -5));
	return true;
}

CustomGraphic::CustomGraphic()
{
}
