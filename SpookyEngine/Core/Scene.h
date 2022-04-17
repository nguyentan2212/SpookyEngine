#pragma once
#include <memory>
#include <vector>
#include "../Graphic/Graphic.h"
#include "Camera2D.h"
#include "ResourceLocator.h"
#include "Grid.h"

using namespace::std;

class Scene
{
public:
	Scene();
	virtual bool Initialize(Matrix coordinateMatrix);
	virtual void Update(double delta);
	virtual void Render();

protected:
	Matrix coordinateMatrix;
	void AddGameObject(shared_ptr<GameObject> obj);
	shared_ptr<GameObject> background;
private:
	vector<shared_ptr<GameObject>> objs;
};

