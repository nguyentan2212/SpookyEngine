#include "GameObject.h"

GameObject::GameObject()
{
	drawableList = vector<shared_ptr<Drawable2D>>(0);
	transform = Transform2D();
}

GameObject::GameObject(const Vector& position)
{
	transform = Transform2D();
	transform.SetLocalPosition(position);
	drawableList = vector<shared_ptr<Drawable2D>>(0);
}

GameObject::GameObject(const Transform2D& transform) : transform(transform)
{
	drawableList = vector<shared_ptr<Drawable2D>>(0);
}

void GameObject::AddSprite(shared_ptr<Sprite> sprite)
{
	drawableList.push_back(sprite);
}

void GameObject::AddAnimation(shared_ptr<Animation> animation)
{
	drawableList.push_back(animation);
}

void GameObject::SetLocalPosition(Vector position)
{
	transform.SetLocalPosition(position);
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
		drawableList[i]->Render(transMat * transform.GetLocalTransform());
	}
}
