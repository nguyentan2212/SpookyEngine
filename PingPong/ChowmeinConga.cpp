#include "ChowmeinConga.h"

ChowmeinConga::ChowmeinConga(string name, double width, double height, Vector pos) : GameObject(name, width, height, pos)
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// character's animation
	// left direction
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/idle/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, 50);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	/*animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/idle/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, 50);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);*/

	isDrawBox = true;
}
void ChowmeinConga::Initialize()
{
}

void ChowmeinConga::Update(double delta)
{
	GameObject::Update(delta);
}

void ChowmeinConga::Render(Matrix transMat)
{
	GameObject::Render(transMat);
}
