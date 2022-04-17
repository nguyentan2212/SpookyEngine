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
		grid[i] = vector<shared_ptr<Cell>>(this->col, make_shared<Cell>());
	}
}

void Grid::AddGameObject(shared_ptr<GameObject> obj)
{
	Vector position = obj->GetLocalPosition();
	int cellX = position.GetValueX() / cellWidth;
	int cellY = position.GetValueY() / cellHeight;
	grid[cellY][cellX]->AddGameObject(obj);
}

void Grid::Move(shared_ptr<GameObject> obj, Vector oldPostion)
{
	// which cell it was in.
	int oldCellX = oldPostion.GetValueX() / cellWidth;
	int oldCellY = oldPostion.GetValueY() / cellHeight;
	// which cell it is moving to.
	Vector position = obj->GetLocalPosition();
	int cellX = position.GetValueX() / cellWidth;
	int cellY = position.GetValueY() / cellHeight;

	OutputDebugStringW((L"[Grid]: " + to_wstring(cellX) + L", " + to_wstring(cellY) + L"\n").c_str());

	// if it didn't change cells, we're done.
	if (oldCellX == cellX && oldCellY == cellY) return;

	// remove from the old cell.
	grid[oldCellY][oldCellX]->RemoveGameObject(obj);
	// add it back to the grid at its new cell.
	grid[cellY][cellX]->AddGameObject(obj);
}

vector<shared_ptr<GameObject>> Grid::GetObjectOnCamera(double b, double l, double t, double r)
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
