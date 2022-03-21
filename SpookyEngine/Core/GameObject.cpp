#include "GameObject.h"

GameObject::GameObject() : Transform2D()
{
	sprites = vector<shared_ptr<Sprite>>(0);
}

GameObject::GameObject(const Vector3D& position)
{
	SetLocalPosition(position);
	sprites = vector<shared_ptr<Sprite>>(0);
}

GameObject::GameObject(const Transform2D& transform) : Transform2D(transform)
{
}

void GameObject::AddSprite(shared_ptr<Sprite> sprite)
{
	sprites.push_back(sprite);
}

void GameObject::AddAnimation(shared_ptr<Animation> animation)
{
	animations.push_back(animation);
}

void GameObject::Update(double delta)
{
	for (int i = 0; i < animations.size(); i++)
	{
		animations[i]->Update(delta);
	}
}

void GameObject::Render(Vector3D camPos)
{

	for (int i = 0; i < sprites.size(); i++)
	{
		sprites[i]->Render(GetLocalTransform(), camPos);
	}
	for (int i = 0; i < animations.size(); i++)
	{
		animations[i]->Render(GetLocalTransform(), camPos);
	}
}
