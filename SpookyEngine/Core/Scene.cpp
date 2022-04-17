#include "Scene.h"

Scene::Scene()
{
	background = shared_ptr<GameObject>(new GameObject());
}

bool Scene::Initialize(Matrix coordinateMatrix)
{
	this->coordinateMatrix = coordinateMatrix;
	return false;
}

void Scene::Update(double delta)
{
	shared_ptr<Grid> grid = Grid::GetInstance();
	for (int i = 0; i < objs.size(); i++)
	{
		Vector oldPosition = objs[i]->GetLocalPosition();
		objs[i]->Update(delta);
		grid->Move(objs[i], oldPosition);
	}
	if (background != nullptr)
	{
		background->Update(delta);
	}
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	camera->Update();
}

void Scene::Render()
{
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	Vector bottomLeft = camera->GetPosition();
	Vector topRight = bottomLeft + camera->GetSize();

	Matrix transMat = coordinateMatrix * Matrix::Translation(camera->GetPosition() * -1);

	shared_ptr<Graphic> graphic = Graphic::GetInstance();
	shared_ptr<Grid> grid = Grid::GetInstance();
	vector<shared_ptr<GameObject>> result = grid->GetObjectOnCamera(bottomLeft.GetValueY(), bottomLeft.GetValueX(), 
																	topRight.GetValueY(), topRight.GetValueX());

	graphic->BeginRender();

	graphic->BeginSprite();
	if (background != nullptr)
	{
		background->Render(transMat);
	}
	for (int i = 0; i < result.size(); i++)
	{
		result[i]->Render(transMat);
	}
	graphic->EndSprite();

	for (int i = 0; i < objs.size(); i++)
	{
		if (result[i]->isDrawBox)
		{
			Vector pos = transMat * result[i]->GetLocalPosition();
			graphic->DrawBox(pos.GetValueX(), pos.GetValueY(), result[i]->width, objs[i]->height);
		}
	}


	graphic->EndRender();
}

void Scene::AddGameObject(shared_ptr<GameObject> obj)
{
	objs.push_back(obj);
	shared_ptr<Grid> grid = Grid::GetInstance();
	grid->AddGameObject(obj);
}
