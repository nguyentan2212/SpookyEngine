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
}

void Scene::Render(Vector3D camPos)
{
	for (int i = 0; i < objs.size(); i++)
	{
		objs[i]->Render(camPos);
	}
}
