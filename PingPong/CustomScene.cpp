#include "CustomScene.h"

bool CustomScene::Initialize()
{
    shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();

    // background's sprites
    shared_ptr<GameObject> background = shared_ptr<GameObject>(new GameObject());
    shared_ptr<Sprite> sprite = locator->GetSprite("background/0.png");
    sprite->SetLocalPosition(Vector(1186.5 , 136));
    sprite->SetZIndex(1);
    background->AddSprite(sprite);
    sprite = locator->GetSprite("background/1.png");
    sprite->SetLocalPosition(Vector(804, 130.5));
    sprite->SetZIndex(0.8);
    background->AddSprite(sprite);

    // background's animation
    shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());
    for (int i = 0; i < 7; i++)
    {
        vector<shared_ptr<Sprite>> sprites(0);
        
        string name = "beach_2/" + to_string(2 * i) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetLocalPosition(Vector(0, 52));
        sprites.push_back(sprite);

        name = "beach_2/" + to_string(2 * i + 1) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetLocalPosition(Vector(0 , 20));
        sprites.push_back(sprite);
        animation->AddFrame(sprites, 50);
    }
    animation->SetLocalPosition(Vector(281.5, 0));
    animation->SetZIndex(0.7);
    background->AddAnimation(animation);
    background->SetLocalPosition(Vector(0, 0));
    objs.push_back(background);

    // character's animation
    animation = shared_ptr<Animation>(new Animation());
    for (int i = 0; i < 7; i++)
    {
        string name = "idle/" + to_string(i) + ".png";
        sprite = locator->GetSprite(name, Vector(-1, 1, 0));
        animation->AddFrame(sprite, 50);
    }

    animation->SetZIndex(0);
    shared_ptr<Character> character = shared_ptr<Character>(new Character());
    character->AddAnimation(animation);
    character->SetLocalPosition(Vector(25, 25));
    character->width = 48;
    character->height = 44;
    character->isDrawBox = true;
    objs.push_back(character);

    //shared_ptr<Camera2D> camera = Camera2D::GetInstance();
    //camera->FollowObj(character);

    return true;
}
