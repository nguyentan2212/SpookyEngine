#include "Character.h"

void Character::Initialize()
{
	
}

void Character::Update(double delta)
{
	GameObject::Update(delta);

	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();

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
		transform.Translate(0, -1 * delta);
	}
	if (keyboard->KeyIsPressed(VK_DOWN))
	{
		transform.Translate(0, 1 * delta);
	}
}
