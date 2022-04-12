#pragma once
#include <memory>
#include <vector>
#include "GameObject.h"
#include "../Graphic/Graphic.h"
#include "ResourceLocator.h"

using namespace::std;

class Scene
{
public:
	Scene();

	virtual bool Initialize() { return true; }
	virtual void Update(double delta);
	virtual void Render(Matrix coordinateMatrix);

protected:
	vector<shared_ptr<GameObject>> objs;
};

