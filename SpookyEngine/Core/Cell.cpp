#include "Cell.h"

Cell::Cell()
{
	objs = vector<shared_ptr<GameObject>>(0);
}

void Cell::AddGameObject(shared_ptr<GameObject> obj)
{
	objs.push_back(obj);
}

void Cell::RemoveGameObject(shared_ptr<GameObject> obj)
{
	int pos = -1;
	for (int i = 0; i < objs.size(); i++)
	{
		if (objs[i]->name == obj->name)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		return;
	}
	objs.erase(objs.begin() + pos);
}

