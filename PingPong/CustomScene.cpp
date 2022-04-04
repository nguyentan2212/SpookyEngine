#include "CustomScene.h"

bool CustomScene::Initialize()
{
    shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();

    // background's sprites
    shared_ptr<GameObject> background = shared_ptr<GameObject>(new GameObject());
    shared_ptr<Sprite> sprite = locator->GetSprite("background/0.png");
    sprite->SetLocalPosition(Vector(0, -63));
    background->AddSprite(sprite);
    sprite = locator->GetSprite("background/1.png");
    sprite->SetLocalPosition(Vector(0, -36));
    background->AddSprite(sprite);

    // background's animation
    shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());
    for (int i = 0; i < 7; i++)
    {
        vector<shared_ptr<Sprite>> sprites(0);
        
        string name = "beach_2/" + to_string(2 * i) + ".png";
        sprite = locator->GetSprite(name);
        sprites.push_back(sprite);

        name = "beach_2/" + to_string(2 * i + 1) + ".png";
        sprite = locator->GetSprite(name);
        sprite->SetLocalPosition(Vector(0, 24));
        sprites.push_back(sprite);
        animation->AddFrame(sprites, 50);
    }
    animation->SetLocalPosition(Vector(0, 160));
    background->AddAnimation(animation);
    background->SetLocalPosition(Vector(0, 0));
    objs.push_back(background);

    // character's animation
    animation = shared_ptr<Animation>(new Animation());
    for (int i = 0; i < 7; i++)
    {
        string name = "idle/" + to_string(i) + ".png";
        sprite = locator->GetSprite(name);
        sprite->isFlipped = true;
        animation->AddFrame(sprite, 50);
    }

    shared_ptr<Character> character = shared_ptr<Character>(new Character());
    character->AddAnimation(animation);
    character->SetLocalPosition(Vector(50, 50));
    objs.push_back(character);

    //shared_ptr<Camera2D> camera = Camera2D::GetInstance();
    //camera->FollowObj(character);

    return true;
}
