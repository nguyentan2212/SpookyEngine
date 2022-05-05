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
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	camera->Update();

	shared_ptr<Grid> grid = Grid::GetInstance();
	for (int i = 0; i < objs.size(); i++)
	{
		Vector oldPosition = objs[i]->GetPosition();
		objs[i]->Update(delta);
		grid->Move(objs[i], oldPosition);
	}

	if (background != nullptr)
	{
		background->Update(delta);
	}

}

void Scene::Render()
{
	shared_ptr<Camera2D> camera = Camera2D::GetInstance();
	Vector bottomLeft = camera->GetPosition();
	Vector topRight = bottomLeft + camera->GetSize();
	Matrix transMat = coordinateMatrix * Matrix::Translation(camera->GetPosition() * -1);

	shared_ptr<Graphic> graphic = Graphic::GetInstance();
	shared_ptr<Grid> grid = Grid::GetInstance();

	// get objs on camera
	vector<shared_ptr<GameObject>> result = grid->GetObjectsOnCamera(bottomLeft.GetValueY(), bottomLeft.GetValueX(), 
																	topRight.GetValueY(), topRight.GetValueX());

	// OutputDebugStringW((L"[Scene's result array]: " + to_wstring(result.size()) + L"\n").c_str());

	graphic->BeginRender();

	graphic->BeginSprite();

	// draw background
	if (background != nullptr)
	{
		background->Render(transMat);
	}

	// draw obj's graphic
	for (int i = 0; i < result.size(); i++)
	{
		result[i]->Render(transMat);
	}
	graphic->EndSprite();

	// draw bounding box
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i]->isDrawBox)
		{
			BoundingBox box = result[i]->GetBoundingBox();
			Vector position = transMat * box.position;
			graphic->DrawBox(position.GetValueX(), position.GetValueY(), box.width, box.height);
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
