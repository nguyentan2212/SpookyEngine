#include "Collision.h"

bool Collision::isColliding(BoundingBox obj, BoundingBox other)
{
	double otherLeft = other.postion.GetValueX() - other.width / 2;
	double otherBottom = other.postion.GetValueY() - other.height / 2;
	double objLeft = obj.postion.GetValueX() - obj.width / 2;
	double objBottom = obj.postion.GetValueY() - obj.height / 2;

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

	double dxEntry, dxExit;
	double dyEntry, dyExit;

	double txEntry, txExit;
	double tyEntry, tyExit;

	double otherLeft = other.postion.GetValueX() - other.width / 2;
	double otherBottom = other.postion.GetValueY() - other.height / 2;
	double objLeft = obj.postion.GetValueX() - obj.width / 2;
	double objBottom = obj.postion.GetValueY() - obj.height / 2;

	if (obj.velocity.GetValueX() > 0)
	{
		dxEntry = otherLeft - (objLeft + obj.width);
		dxExit = (otherLeft + other.width) - objLeft;
	}
	else 
	{
		dxEntry = (otherLeft + other.width) - objLeft;
		dxExit = otherLeft - (objLeft + obj.width);
	}

	if (obj.velocity.GetValueY() > 0)
	{
		dyEntry = otherBottom - (objBottom + obj.height);
		dyExit = (otherBottom + other.height) - objBottom;
	}
	else 
	{
		dyEntry = (otherBottom + other.height) - objBottom;
		dyExit = otherBottom - (objBottom + obj.height);
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

	if (entryTime > exitTime || (txEntry < 0.0f && tyEntry < 0.0f) || txEntry > 1.0f || tyEntry > 1.0f)
	{
		return 1;
	}

	return entryTime;
}
