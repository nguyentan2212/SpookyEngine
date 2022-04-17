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
	GameObject::Update(delta);

	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();
	Vector oldPosition = this->GetLocalPosition();

	if (keyboard->KeyIsPressed(VK_LEFT))
	{
		transform.Translate(-1 * delta, 0);
		state = LEFT;
	}
	if (keyboard->KeyIsPressed(VK_RIGHT))
	{
		transform.Translate(1 * delta, 0);
		state = RIGHT;
	}
	if (keyboard->KeyIsPressed(VK_UP))
	{
		transform.Translate(0, 1 * delta);
	}
	if (keyboard->KeyIsPressed(VK_DOWN))
	{
		transform.Translate(0, -1 * delta);
	}
	Vector pos = this->transform.GetLocalPosition();
	shared_ptr<Grid> grid = Grid::GetInstance();

	//OutputDebugStringW((L"[Character]: " + to_wstring(pos.GetValueX()) + L", " + to_wstring(pos.GetValueY()) + L"\n").c_str());
}

void Character::Render(Matrix transMat)
{
	transMat = transMat * GetWorldTransform();
	if (state == LEFT)
	{
		drawableList[0]->Render(transMat);
	}
	else {
		drawableList[1]->Render(transMat);
	}
}

void Character::OnCollision(vector<CollisionEvent> collisionEvents)
{
	shared_ptr<GameObject> obj = collisionEvents[0].obj;
	wstring name = StringConverter::StringToWide(obj->name);
	Vector pos = GetWorldPosition();
	OutputDebugStringW((L"[Character]: " + name + L", x = " + to_wstring(pos.GetValueX()) + L"\n").c_str());
}
