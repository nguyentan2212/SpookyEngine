#include "Grid.h"

shared_ptr<Grid> Grid::instance = nullptr;

Grid::Grid()
{
	this->width = 0;
	this->height = 0;
	this->cellWidth = 0;
	this->cellHeight = 0;
	this->row = 0;
	this->col = 0;
	grid = vector<vector<shared_ptr<Cell>>>(0);
}

//bool Grid::isColliding(BoundingBox obj, BoundingBox other)
//{
//	double otherLeft = other.postion.GetValueX() - other.width / 2;
//	double otherBottom = other.postion.GetValueY() - other.height / 2;
//	double objLeft = obj.postion.GetValueX() - obj.width / 2;
//	double objBottom = obj.postion.GetValueY() - obj.height / 2;
//
//	double left = otherLeft - (objLeft + obj.width);
//	double bottom = otherBottom - (objBottom + obj.height);
//	double right = (otherLeft + other.width) - objLeft;
//	double top = (otherBottom + other.height) - objBottom;
//
//	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
//}

shared_ptr<Grid> Grid::GetInstance()
{
	if (instance == nullptr)
	{
		instance = shared_ptr<Grid>(new Grid());
	}
	return instance;
}

void Grid::Initialize(int width, int height, int cellWidth, int cellHeight)
{
	this->width = width;
	this->height = height;
	this->cellWidth = cellWidth;
	this->cellHeight = cellHeight;
	this->row = height / cellHeight + 1;
	this->col = width / cellWidth + 1;
	grid = vector<vector<shared_ptr<Cell>>>(this->row);
	for (int i = 0; i < this->row; i++)
	{
		grid[i] = vector<shared_ptr<Cell>>(this->col);
		for (int j = 0; j < this->col; j++)
		{
			grid[i][j] = shared_ptr<Cell>(new Cell());
		}
	}
}

void Grid::AddGameObject(shared_ptr<GameObject> obj)
{
	Vector position = obj->GetPosition();
	int cellX = position.GetValueX() / cellWidth; // col
	int cellY = position.GetValueY() / cellHeight; // row
	grid[cellY][cellX]->AddGameObject(obj);
	objsList[obj->name] = obj;
}

void Grid::Move(shared_ptr<GameObject> obj, Vector oldPostion)
{
	// which cell it was in.
	int oldCellX = oldPostion.GetValueX() / cellWidth;
	int oldCellY = oldPostion.GetValueY() / cellHeight;
	// which cell it is moving to.
	Vector position = obj->GetPosition();
	int cellX = position.GetValueX() / cellWidth;
	int cellY = position.GetValueY() / cellHeight;

	// OutputDebugStringW((L"[Grid]: " + to_wstring(cellX) + L", " + to_wstring(cellY) + L"\n").c_str());

	// if it didn't change cells, we're done.
	if (oldCellX == cellX && oldCellY == cellY) return;

	// remove from the old cell.
	grid[oldCellY][oldCellX]->RemoveGameObject(obj);
	// add it back to the grid at its new cell.
	grid[cellY][cellX]->AddGameObject(obj);
}

vector<shared_ptr<GameObject>> Grid::GetObjectsOnCamera(double b, double l, double t, double r)
{
	int bottom = b / cellHeight;
	if (bottom > 0) bottom--;

	int left = l / cellWidth;
	if (left > 0) left--;

	int top = t / cellHeight;
	if (top < row - 1) top++;

	int right = r / cellWidth;
	if (right < col - 1) right++;

	vector<shared_ptr<GameObject>> result(0);
	for (int i = bottom; i <= top; i++)
	{
		for (int j = left; j <= right; j++)
		{
			vector<shared_ptr<GameObject>> temp = grid[i][j]->GetGameObjectList();
			if (temp.size() > 0)
			{
				result.insert(result.end(), temp.begin(), temp.end());
			}
		}
	}
	
	return result;
}

vector<CollisionEvent> Grid::GetObjectsCollideWith(shared_ptr<GameObject> gameObj, double delta)
{
	// which cell it is in.
	Vector position = gameObj->GetPosition();
	int cellX = position.GetValueX() / cellWidth;
	int cellY = position.GetValueY() / cellHeight;

	int bottom = 0;
	int left = 0;
	int top = 0;
	int right = 0;

	if (cellX > 0) 
		left = cellX - 1;

	if (cellX < col - 1) 
		right = cellX + 1;

	if (cellY > 0)
		bottom = cellY - 1;

	if (cellY < row - 1)
		top = cellY + 1;

	vector<shared_ptr<GameObject>> result(0);
	for (int i = bottom; i <= top; i++)
	{
		for (int j = left; j <= right; j++)
		{
			vector<shared_ptr<GameObject>> temp = grid[i][j]->GetGameObjectList();
			if (temp.size() > 0)
			{
				result.insert(result.end(), temp.begin(), temp.end());
			}
		}
	}
	vector<CollisionEvent> collision(0);
	BoundingBox obj = gameObj->GetBoundingBox(delta);
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i]->name != gameObj->name) {
			BoundingBox other = result[i]->GetBoundingBox(delta);
			CollisionEvent collisionEvent;
			
			collisionEvent.entryTime = Collision::sweptAABB(obj, other, collisionEvent.direction);
			// collisionEvent.entryTime = Collision::isColliding(obj, other) ? 0.5 : 1;
			if (collisionEvent.entryTime < 1)
			{
				// OutputDebugStringW((L"[Grid]: x = " + to_wstring(other.position.GetValueX()) + L", y = " + to_wstring(other.position.GetValueY()) + L", direction = " + to_wstring(collisionEvent.direction) + L"\n").c_str());
				collisionEvent.obj = result[i];
				collision.push_back(collisionEvent);
			}
		}
	}

	return collision;
}

CollisionEvent Grid::CollideWithGameObject(BoundingBox obj, string otherName, double delta)
{
	CollisionEvent collisionEvent;
	shared_ptr<GameObject> otherObj = objsList.at(otherName);
	if (otherObj == nullptr)
	{
		collisionEvent.entryTime = 1.0;
		return collisionEvent;
	}
	BoundingBox other = otherObj->GetBoundingBox(delta);

	collisionEvent.entryTime = Collision::sweptAABB(obj, other, collisionEvent.direction);

	return collisionEvent;
}

void Grid::RemoveGameObject(shared_ptr<GameObject> obj)
{
	// which cell it is moving to.
	Vector position = obj->GetPosition();
	int cellX = position.GetValueX() / cellWidth;
	int cellY = position.GetValueY() / cellHeight;

	grid[cellY][cellX]->RemoveGameObject(obj);
}
