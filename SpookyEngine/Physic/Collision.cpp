#include "Collision.h"

bool Collision::isColliding(BoundingBox obj, BoundingBox other)
{
	double otherLeft = other.position.GetValueX() - other.width / 2;
	double otherBottom = other.position.GetValueY() - other.height / 2;
	double objLeft = obj.position.GetValueX() - obj.width / 2;
	double objBottom = obj.position.GetValueY() - obj.height / 2;

	double left = otherLeft - (objLeft + obj.width);
	double bottom = otherBottom - (objBottom + obj.height);
	double right = (otherLeft + other.width) - objLeft;
	double top = (otherBottom + other.height) - objBottom;

	return !(left > 0 || right < 0 || top < 0 || bottom > 0);
}

double Collision::sweptAABB(BoundingBox obj, BoundingBox other, int& direction)
{
	if (other.velocity.GetValueX() != 0 || other.velocity.GetValueY() != 0)
	{
		Vector temp = obj.velocity - other.velocity;
		obj.velocity = temp;
		other.velocity = Vector::Zero();
	}

	BoundingBox sweptBroadphaseBox = getSweptBroadphaseBox(obj);
	if (!isColliding(sweptBroadphaseBox, other))
	{
		return 1.0;
	}

	double dxEntry, dxExit;
	double dyEntry, dyExit;

	double txEntry, txExit;
	double tyEntry, tyExit;

	double otherLeft = other.position.GetValueX() - other.width / 2.0;
	double otherBottom = other.position.GetValueY() - other.height / 2.0;
	double objLeft = obj.position.GetValueX() - obj.width / 2.0;
	double objBottom = obj.position.GetValueY() - obj.height / 2.0;

	if (obj.velocity.GetValueX() > 0)
	{
		dxEntry = otherLeft - (obj.position.GetValueX() + obj.width / 2.0);
		dxExit = (other.position.GetValueX() + other.width / 2.0) - objLeft;
	}
	else 
	{
		dxEntry = (other.position.GetValueX() + other.width / 2.0) - objLeft;
		dxExit = otherLeft - (obj.position.GetValueX() + obj.width / 2.0);
	}

	if (obj.velocity.GetValueY() > 0)
	{
		dyEntry = otherBottom - (obj.position.GetValueY() + obj.height / 2.0);
		dyExit = (other.position.GetValueY() + other.height / 2.0) - objBottom;
	}
	else 
	{
		dyEntry = (other.position.GetValueY() + other.height / 2.0) - objBottom;
		dyExit = otherBottom - (obj.position.GetValueY() + obj.height / 2.0);
	}

	if (obj.velocity.GetValueX() == 0)
	{
		txEntry = -std::numeric_limits<double>::infinity();
		txExit = std::numeric_limits<double>::infinity();
	}
	else
	{
		txEntry = dxEntry / obj.velocity.GetValueX();
		txExit = dxExit / obj.velocity.GetValueX();
	}

	if (obj.velocity.GetValueY() == 0)
	{
		tyEntry = -std::numeric_limits<double>::infinity();
		tyExit = std::numeric_limits<double>::infinity();
	}
	else
	{
		tyEntry = dyEntry / obj.velocity.GetValueY();
		tyExit = dyExit / obj.velocity.GetValueY();
	}

	double entryTime = max(txEntry, tyEntry);
	double exitTime = min(txExit, tyExit);

	OutputDebugStringW((L"[Collision]: " + to_wstring(txEntry) + L", " + to_wstring(tyEntry) + L"\n").c_str());
	if (entryTime > exitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
	{
		return 1;
	}

	if (txEntry > tyEntry)
	{
		if (dxEntry > 0.0f)
		{
			direction = RIGHT;
		}
		else
		{
			direction = LEFT;
		}
	}
	else
	{
		if (dyEntry > 0.0f)
		{
			direction = UP;
		}
		else
		{
			direction = DOWN;
		}
	}


	return entryTime;
}

BoundingBox Collision::getSweptBroadphaseBox(BoundingBox obj)
{
	BoundingBox box;
	box.velocity = obj.velocity;

	box.width = obj.width + abs(obj.velocity.GetValueX());
	box.height = obj.height + abs(obj.velocity.GetValueY());
	box.position = obj.position + obj.velocity / 2.0;
	
	return box;
}
