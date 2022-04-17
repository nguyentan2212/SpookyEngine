#include "CustomScene.h"

CustomScene::CustomScene() : Scene()
{
}

bool CustomScene::Initialize(Matrix coordinateMatrix)
{
    Scene::Initialize(coordinateMatrix);
    shared_ptr<Grid> grid = Grid::GetInstance(); 
    grid->Initialize(3000, 1000, 120, 120);

    shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();

    // background's sprites    
    shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());
    shared_ptr<Sprite> sprite = locator->GetSprite("background/0.png");
    sprite->SetLocalPosition(Vector(1700 , 227));
    sprite->SetZIndex(1);
    background->AddSprite(sprite);
    sprite = locator->GetSprite("background/1.png");
    sprite->SetLocalPosition(Vector(1206, 197));
    sprite->SetZIndex(0.8);
    background->AddSprite(sprite);

    // background's animation
    for (int i = 0; i < 7; i++)
    {
        vector<shared_ptr<Sprite>> sprites(0);
        
        string name = "beach_2/" + to_string(2 * i) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetLocalPosition(Vector(0, 79));
        sprites.push_back(sprite);

        name = "beach_2/" + to_string(2 * i + 1) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetLocalPosition(Vector(0 , 32));
        sprites.push_back(sprite);
        animation->AddFrame(sprites, 50);
    }
    animation->SetLocalPosition(Vector(420, 0));
    animation->SetZIndex(0.7);
    background->AddAnimation(animation);
    background->SetLocalPosition(Vector(0, 0));

    // character's animation
    animation = shared_ptr<Animation>(new Animation());
    for (int i = 0; i < 7; i++)
    {
        string name = "idle/" + to_string(i) + ".png";
        sprite = locator->GetSprite(name, Vector(-1, 1));
        animation->AddFrame(sprite, 50);
    }

    animation->SetZIndex(0);
    shared_ptr<Character> character = shared_ptr<Character>(new Character());
    character->AddAnimation(animation);
    character->SetLocalPosition(Vector(37, 37));
    character->width = 72;
    character->height = 66;
    character->isDrawBox = true;
    AddGameObject(character);

    shared_ptr<Camera2D> camera = Camera2D::GetInstance();
    camera->FollowObj(character);

    return true;
}
