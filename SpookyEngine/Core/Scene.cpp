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

	for (int i = 0; i < objs.size(); i++)
	{
		objs[i]->Render(transMat);
	}
}
