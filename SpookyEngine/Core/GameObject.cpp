#include "GameObject.h"

GameObject::GameObject(string name)
{
	drawableList = vector<shared_ptr<Drawable2D>>(0);
	transform = Transform2D();
	this->name = name;
}

GameObject::GameObject(string name, double width, double height, const Vector& position)
{
	transform = Transform2D();
	transform.SetPosition(position);
	drawableList = vector<shared_ptr<Drawable2D>>(0);
	this->name = name;
	this->width = width;
	this->height = height;
}

void GameObject::AddSprite(shared_ptr<Sprite> sprite)
{
	drawableList.push_back(sprite);
}

void GameObject::AddAnimation(shared_ptr<Animation> animation)
{
	drawableList.push_back(animation);
}

void GameObject::SetPosition(Vector position)
{
	transform.SetPosition(position);
}

void GameObject::SetVelocity(Vector velocity)
{
	transform.SetVelocity(velocity);
}

void GameObject::Update(double delta)
{
	for (int i = 0; i < drawableList.size(); i++)
	{
		drawableList[i]->Update(delta);
	}
}

void GameObject::Render(Matrix transMat)
{
	for (int i = 0; i < drawableList.size(); i++)
	{
		drawableList[i]->Render(transMat * transform.GetTransformMatrix());
	}
}
