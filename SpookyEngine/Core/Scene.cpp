#include "Scene.h"

Scene::Scene()
{
	objs = vector<shared_ptr<GameObject>>(0);
}

void Scene::Update(double delta)
{
	for (int i = 0; i < objs.size(); i++)
	{
		objs[i]->Update(delta);
	}
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	camera->Update();
}

void Scene::Render(Matrix coordinateMatrix)
{
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	Matrix transMat = coordinateMatrix * Matrix::Translation(camera->GetPosition() * -1);

	shared_ptr<Graphic> graphic = Graphic::GetInstance();
	graphic->BeginRender();

	graphic->BeginSprite();
	for (int i = 0; i < objs.size(); i++)
	{
		objs[i]->Render(transMat);
	}
	graphic->EndSprite();

	for (int i = 0; i < objs.size(); i++)
	{
		if (objs[i]->isDrawBox)
		{
			Vector pos = coordinateMatrix * objs[i]->GetLocalPosition();
			graphic->DrawBox(pos.GetValueX(), pos.GetValueY(), objs[i]->width, objs[i]->height);
		}
	}
	graphic->EndRender();
}
