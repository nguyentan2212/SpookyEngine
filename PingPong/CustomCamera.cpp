#include "CustomCamera.h"

void CustomCamera::Update(double delta)
{
	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();

	if (keyboard->KeyIsPressed(VK_LEFT))
	{
		Translate(-1 * delta, 0);
		
	}
	if (keyboard->KeyIsPressed(VK_RIGHT))
	{
		Translate(1 * delta, 0);
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
