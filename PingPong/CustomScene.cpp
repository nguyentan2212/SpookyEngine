#include "CustomScene.h"

CustomScene::CustomScene() : Scene()
{
}

bool CustomScene::Initialize(Matrix coordinateMatrix)
{
    Scene::Initialize(coordinateMatrix);

    // initialize grid
    shared_ptr<Grid> grid = Grid::GetInstance(); 
    grid->Initialize(3000, 1000, 120, 120);

    shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();

    // background's sprites    
    shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());
    shared_ptr<Sprite> sprite = locator->GetSprite("Background/background/0.png");
    sprite->SetPosition(Vector(1700 , 227));
    sprite->SetZIndex(1);
    background->AddSprite(sprite);
    sprite = locator->GetSprite("Background/background/1.png");
    sprite->SetPosition(Vector(1206, 197));
    sprite->SetZIndex(0.8);
    background->AddSprite(sprite);

    // background's animation
    for (int i = 0; i < 7; i++)
    {
        vector<shared_ptr<Sprite>> sprites(0);
        
        string name = "Background/beach_2/" + to_string(2 * i) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetPosition(Vector(0, 79));
        sprites.push_back(sprite);

        name = "Background/beach_2/" + to_string(2 * i + 1) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetPosition(Vector(0 , 32));
        sprites.push_back(sprite);
        animation->AddFrame(sprites, 50);
    }
    animation->SetPosition(Vector(420, 0));
    animation->SetZIndex(0.7);
    background->AddAnimation(animation);
    background->SetPosition(Vector(0, 0));

    // ChowmeinConga
    shared_ptr<ChowmeinConga> enemy = shared_ptr<ChowmeinConga>(new ChowmeinConga("enemy", 77, 66, Vector(200, 100)));
    AddGameObject(enemy);

    return true;
}
