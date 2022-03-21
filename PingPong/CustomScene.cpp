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

	// ani 1
	shared_ptr<Animation> ani = shared_ptr<Animation>(new Animation());
	double frameRate = 150;
	tx = graphic->GetTexture("character0");
	sprite = graphic->GetSprite(tx, 112, 128, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character1");
	sprite = graphic->GetSprite(tx, 78, 132, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character2");
	sprite = graphic->GetSprite(tx, 89, 135, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character3");
	sprite = graphic->GetSprite(tx, 124, 131, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character4");
	sprite = graphic->GetSprite(tx, 132, 128, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character5");
	sprite = graphic->GetSprite(tx, 101, 128, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character6");
	sprite = graphic->GetSprite(tx, 86, 132, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character7");
	sprite = graphic->GetSprite(tx, 97, 135, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	tx = graphic->GetTexture("character8");
	sprite = graphic->GetSprite(tx, 116, 132, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);
	
	tx = graphic->GetTexture("character9");
	sprite = graphic->GetSprite(tx, 131, 128, 0, 0);
	sprite->SetLocalPosition(Vector3D(0, 0, 0));
	ani->AddFrame(sprite, frameRate);

	// char 1
	obj = shared_ptr<Character>(new Character(Vector3D(150, 150, 0)));
	obj->AddAnimation(ani);
	objs.push_back(obj);

	// obj 2
	obj = shared_ptr<GameObject>(new GameObject(Vector3D(600, 730, 0)));
	obj->AddAnimation(ani);
	objs.push_back(obj);

	// obj 3
	obj = shared_ptr<GameObject>(new GameObject(Vector3D(800, -100, 0)));
	obj->AddAnimation(ani);

	objs.push_back(obj);

    return true;
}
