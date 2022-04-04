#include "ResourceLocator.h"

shared_ptr<ResourceLocator> ResourceLocator::instance = nullptr;

ResourceLocator::ResourceLocator()
{
    fstream file("assets/resource.json");
    initJson = json::parse(file);
}

json ResourceLocator::OpenJson(string jsonPath)
{
    fstream file(jsonPath);
    return json::parse(file);
}

void ResourceLocator::LoadTexture(string name, string path)
{
    shared_ptr<Graphic> graphic = Graphic::GetInstance();
    json textureJson = OpenJson(path + "/" + name + ".json");

    // create texture
    string imagePath = path + "/" + name + ".png";
    wstring stemp = StringConverter::StringToWide(imagePath);
    LPCWSTR limagePath = stemp.c_str();
    json transparent = textureJson["transparent"];
    if (transparent.empty())
    {
        textures[name] = shared_ptr<Texture>(new Texture(graphic->GetDevice(), limagePath));
    }
    else {
        int r = transparent["r"].get<int>();
        int g = transparent["g"].get<int>();
        int b = transparent["b"].get<int>();
        textures[name] = shared_ptr<Texture>(new Texture(graphic->GetDevice(), limagePath, D3DCOLOR_XRGB(r,g,b)));
    }
    

    // load sprites of texture
    json spritesList = textureJson["frames"];
    for (auto& element : spritesList)
    {
        // sprite's name
        string spriteName = element["filename"].get<string>();

        json frame = element["frame"];
        // sprite's size
        double w = frame["w"].get<double>();
        double h = frame["h"].get<double>();
        // sprite's position on sheet
        double x = frame["x"].get<double>();
        double y = frame["y"].get<double>();

        sprites[spriteName] = shared_ptr<Sprite>(new Sprite(textures[name], graphic->GetSpriteHandler(), w, h, x, y));
    }
}

shared_ptr<ResourceLocator> ResourceLocator::GetInstance()
{
    if (instance == nullptr)
    {
        instance = shared_ptr<ResourceLocator>(new ResourceLocator());
    }
    return instance;
}

void ResourceLocator::Initialize()
{
    InitializeTexture();
}

void ResourceLocator::InitializeTexture()
{
    json texturesJson = initJson["textures"];
    for (auto& element : texturesJson)
    {
        string name = element["name"].get<string>();
        string path = DEFAULT_PATH + name;

        LoadTexture(name, path);
    }
}
