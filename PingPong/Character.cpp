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
		Translate(-1 * delta, 0);
		state = LEFT;
	}
	if (keyboard->KeyIsPressed(VK_RIGHT))
	{
		Translate(1 * delta, 0);
		state = RIGHT;
	}
	if (keyboard->KeyIsPressed(VK_UP))
	{
		Translate(0, -1 * delta);
	}
	if (keyboard->KeyIsPressed(VK_DOWN))
	{
		Translate(0, 1 * delta);
	}
}

void Character::Render(Vector3D camPos)
{
	if (animations.size() == 0)
	{
		return;
	}

	GameObject::Render(camPos);
}
