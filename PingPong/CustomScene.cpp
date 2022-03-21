#include "CustomScene.h"

bool CustomScene::Initialize()
{
	shared_ptr<CustomGraphic> graphic = CustomGraphic::GetInstance();

	// background
	shared_ptr<Texture> tx = graphic->GetTexture("background");
	shared_ptr<Sprite> sprite = graphic->GetSprite(tx, 1680, 1050, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));

	shared_ptr<GameObject> obj = shared_ptr<GameObject>(new GameObject(Vector3D(0, 0, 0)));
	obj->AddSprite(sprite);
	objs.push_back(obj);

	// character
	tx = graphic->GetTexture("character");
	shared_ptr<Animation> ani = shared_ptr<Animation>(new Animation());

	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sprite = graphic->GetSprite(tx, 860 / 5, 366 / 2, 860 / 5 * i, 366 / 2 * j);
			sprite->SetLocalPosition(Vector3D(0, 0, 0));
			ani->AddFrame(sprite, 200);
		}
	}
	

	obj = shared_ptr<GameObject>(new GameObject(Vector3D(50, 50, 0)));
	obj->AddAnimation(ani);
	objs.push_back(obj);

    return true;
}
