#pragma once
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>
#include <string>
#include <d3d9.h>
#include "../Graphic/Graphic.h"
#include "../Graphic/Texture.h"
#include "../Graphic/Sprite.h"
#include "../Utils/json.hpp"
#include "../Utils/StringConverter.h"

#define DEFAULT_PATH "assets/textures/"

using namespace::std;
using json = nlohmann::json;

class ResourceLocator
{
public:
	ResourceLocator(ResourceLocator&) = delete;
	void operator=(ResourceLocator&) = delete;
	static shared_ptr<ResourceLocator> GetInstance();

	void Initialize();

	shared_ptr<Texture> GetTexture(string name) const {
		return textures.at(name);
	}

	shared_ptr<Sprite> GetSprite(string name, Vector scaleVec = Vector(1, 1, 0)) const {
		shared_ptr<SpriteInfo> info = sprites.at(name);
		if (info == nullptr)
		{
			return nullptr;
		}
		shared_ptr<Graphic> graphic = Graphic::GetInstance();
		shared_ptr<Sprite> sprite = shared_ptr<Sprite>(new Sprite(info, scaleVec));
		return sprite;
	}
private:
	ResourceLocator();
	static shared_ptr<ResourceLocator> instance;

	json initJson;
	unordered_map<string, shared_ptr<Texture>> textures;
	unordered_map<string, shared_ptr<SpriteInfo>> sprites;

	json OpenJson(string jsonPath);
	void InitializeTexture();
	void LoadTexture(string name, string path);
};

