#pragma once
#include <memory>
#include <vector>
#include "GameObject.h"

using namespace::std;

class Scene
{
public:
	Scene();

	virtual bool Initialize() = 0;
	virtual void Update(double delta);
	virtual void Render(Vector3D camPos);

protected:
	vector<shared_ptr<GameObject>> objs;
};

