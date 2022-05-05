#pragma once
#include <unordered_map>
#include "Cell.h"
#include "GameObject.h"
#include "../Physic/Collision.h"

using namespace::std;

class GameObject;
class Cell;

struct CollisionEvent
{
	double entryTime;
	int direction;
	shared_ptr<GameObject> obj;
};

class Grid
{
public:
	Grid(Grid&) = delete;
	void operator=(Grid&) = delete;

	static shared_ptr<Grid> GetInstance();
	void Initialize(int width, int height, int cellWidth, int cellHeight);
	void AddGameObject(shared_ptr<GameObject> obj);
	void Move(shared_ptr<GameObject> obj, Vector oldPostion);
	vector<shared_ptr<GameObject>> GetObjectsOnCamera(double b, double l, double t, double r);
	vector<CollisionEvent> GetObjectsCollideWith(shared_ptr<GameObject> gameObj, double delta);
	CollisionEvent CollideWithGameObject(BoundingBox obj, string otherName, double delta);

private:
	int width, height;
	int col, row;
	int cellWidth, cellHeight;
	vector<vector<shared_ptr<Cell>>> grid;
	unordered_map<string, shared_ptr<GameObject>> objsList;
	Grid();	
	static shared_ptr<Grid> instance;

//	bool isColliding(BoundingBox obj, BoundingBox other);
};

