#include "ChowmeinConga.h"

ChowmeinConga::ChowmeinConga(string name, double width, double height, Vector pos) : GameObject(name, width, height, pos)
{
	isDrawBox = true;
	InitIdleAnimation();
	InitWalkingAnimation();
	InitAttackAnimation();
	InitEatingAnimation();
	InitDeathAnimation();
}
void ChowmeinConga::Initialize()
{
}

void ChowmeinConga::Update(double delta)
{
	shared_ptr<KeyboardClass> keyboard = KeyboardClass::GetInstance();
	double speed = 0.15;

	if (state == DEATH && drawableList[state + direction]->IsDrawFinished)
	{
		isDestroyed = true;
		return;
	}
	// idle <--> walking, idle <--> attack, idle <--> eating, all state --> death
	if (keyboard->KeyIsPressed(VK_LEFT))
	{
		SetVelocity(Vector(-speed, 0));
		ChangeState(WALKING, LEFT);
	}
	else if (keyboard->KeyIsPressed(VK_RIGHT))
	{
		SetVelocity(Vector(speed, 0));
		ChangeState(WALKING, RIGHT);
	}
	else if (keyboard->KeyIsPressed(0x41)) // button A
	{
		SetVelocity(Vector::Zero());
		ChangeState(ATTACK, direction);
	}
	else if (keyboard->KeyIsPressed(0x42)) // button B
	{
		ChangeState(EATING, direction);
	}
	else if (keyboard->KeyIsPressed(0x43)) // button c
	{
		ChangeState(DEATH, direction);
		//isDestroyed = true;
	}
	else
	{
		SetVelocity(Vector::Zero());
		ChangeState(IDLE, direction);
	}
		
	OutputDebugStringW((L"[Conga]: state = " + to_wstring(state) + L", direction = " + to_wstring(direction)).c_str());

	transform.Update(delta);
	GameObject::Update(delta);
}

void ChowmeinConga::Render(Matrix transMat)
{
	if (isDestroyed)
	{
		return;
	}
	transMat = transMat * transform.GetTransformMatrix();
	drawableList[state + direction]->Render(transMat);
}

bool ChowmeinConga::ChangeState(int newState, int newDirection)
{
	if (newState > DEATH || newState < 0)
	{
		return false;
	}
	if (newDirection > 1 || newDirection < 0)
	{
		return false;
	}
	// all state <--> idle, all state --> death
	switch (state)
	{
	case WALKING:
	{
		if (newState == IDLE || newState == DEATH)
		{
			state = newState;
			direction = newDirection;
			return true;
		}
		else if (newState == WALKING)
		{
			direction = newDirection;
			return true;
		}
		break;
	}
	case EATING:
	case ATTACK:
	{
		int oldIndex = state + direction;
		if ((newState == IDLE && drawableList[oldIndex]->IsDrawFinished) || newState == DEATH)
		{
			state = newState;
			direction = newDirection;
			return  true;
		}
		break;
	}
	case DEATH:
	{
		return false;
	}
	default: // idle
	{
		state = newState;
		direction = newDirection;
		return true;
	}
	}
	return false;
}

void ChowmeinConga::InitIdleAnimation()
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// left direction
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/idle/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/idle/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

}

void ChowmeinConga::InitWalkingAnimation()
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// left direction
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/walking/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 7; i++)
	{
		string spriteName = "ChowmeinConga/walking/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);
}

void ChowmeinConga::InitAttackAnimation()
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// attack 1
	// left direction
	for (int i = 0; i < 26; i++)
	{
		string spriteName = "ChowmeinConga/attack/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 26; i++)
	{
		string spriteName = "ChowmeinConga/attack/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);
}

void ChowmeinConga::InitEatingAnimation()
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// left direction
	for (int i = 0; i < 27; i++)
	{
		string spriteName = "ChowmeinConga/eating/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 27; i++)
	{
		string spriteName = "ChowmeinConga/eating/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, FRAME_TIME);
	}
	animation->SetZIndex(0);
	AddAnimation(animation);
}

void ChowmeinConga::InitDeathAnimation()
{
	shared_ptr<ResourceLocator> locator = ResourceLocator::GetInstance();
	shared_ptr<Animation> animation = shared_ptr<Animation>(new Animation());

	// left direction
	for (int i = 0; i < 26; i++)
	{
		string spriteName = "ChowmeinConga/death/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(1, 1));
		animation->AddFrame(sprite, FRAME_TIME * 2);
		if (i == 19)
			sprite->SetPosition(Vector(0, -30));
	}
	animation->SetZIndex(0);
	AddAnimation(animation);

	// right direction
	animation = shared_ptr<Animation>(new Animation());
	for (int i = 0; i < 26; i++)
	{
		string spriteName = "ChowmeinConga/death/" + to_string(i) + ".png";
		shared_ptr<Sprite> sprite = locator->GetSprite(spriteName, Vector(-1, 1));
		animation->AddFrame(sprite, FRAME_TIME * 2);
		if (i == 19)
			sprite->SetPosition(Vector(0, -30));
	}
	animation->SetZIndex(0);
	AddAnimation(animation);
}
