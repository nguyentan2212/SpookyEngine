#pragma once
#include <vector>
#include <string>
#include <memory>
#include "GameObject.h"

using namespace::std;

class Cell
{
public:
	Cell();
	void AddGameObject(shared_ptr<GameObject> obj);
	void RemoveGameObject(shared_ptr<GameObject> obj);
	vector<shared_ptr<GameObject>> GetGameObjectList() const {
		return objs;
	}
private:
	vector<shared_ptr<GameObject>> objs;
};

