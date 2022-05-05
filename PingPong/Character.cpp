#include "Character.h"

Character::Character(string name, double width, double height, Vector pos) : GameObject(name, width, height, pos)
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
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/idle/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, 50);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	isDrawBox = true;
}

void Character::Initialize()
{
	
}

void Character::Update(double delta)
{
	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();
	double speed = 0.5;

	if (keyboard->KeyIsPressed(VK_LEFT))
	{
		SetVelocity(Vector(-speed, 0));
		state = LEFT;
	}
	else if (keyboard->KeyIsPressed(VK_RIGHT))
	{
		SetVelocity(Vector(speed, 0));
		state = RIGHT;
	}
	else if (keyboard->KeyIsPressed(VK_UP))
	{
		SetVelocity(Vector(0, speed));
	}
	else if (keyboard->KeyIsPressed(VK_DOWN))
	{
		SetVelocity(Vector(0, -speed));
	}
	else
	{
		SetVelocity(Vector::Zero());
	}

	shared_ptr<Grid> grid = Grid::GetInstance();
	BoundingBox box = GetBoundingBox(delta);
	CollisionEvent collisionEvent = grid->CollideWithGameObject(box, "enemy", delta);
	Vector pos = this->transform.GetPosition();

	transform.Translate(box.velocity * collisionEvent.entryTime);

	if (collisionEvent.entryTime < 1.0)
	{
		// OutputDebugStringW((L"[Character]: " + to_wstring(pos.GetValueX()) + L", " + to_wstring(pos.GetValueY()) + L"\n").c_str());
		SetVelocity(Vector::Zero());
	}
	GameObject::Update(delta);

	//OutputDebugStringW((L"[Character]: " + to_wstring(pos.GetValueX()) + L", " + to_wstring(pos.GetValueY()) + L"\n").c_str());
}

void Character::Render(Matrix transMat)
{
	transMat = transMat * transform.GetTransformMatrix();
	if (state == LEFT)
	{
		drawableList[0]->Render(transMat);
	}
	else {
		drawableList[1]->Render(transMat);
	}
}
