#pragma once
#include <vector>
#include <memory>
#include <string>
#include "../Math/Transform2D.h"
#include "../Math/Vector.h"
#include "../Graphic/Sprite.h"
#include "../Graphic/Animation.h"
#include "Grid.h"
#include "../Physic/Collision.h"

using namespace::std;

struct CollisionEvent;
class GameObject
{
public:
	GameObject(string name = "default");
	GameObject(string name, double width, double height, const Vector& position);

	virtual void Initialize() {};
	virtual void Update(double delta);
	virtual void Render(Matrix transMat);
	virtual void OnCollision(vector<CollisionEvent> collisionEvents) {}

	void AddSprite(shared_ptr<Sprite> sprite);
	void AddAnimation(shared_ptr<Animation> animation);
	void SetLocalPosition(Vector position);
	void SetVelocity(Vector velocity);
	void SetCoordinate(Matrix coordinate);

	Vector GetLocalPosition() const {
		return transform.GetLocalPosition();
	}
	BoundingBox GetBoundingBox() const {
		Matrix temp = coordinateMatrix;
		BoundingBox box;
		box.width = width;
		box.height = height;
		box.postion = temp * transform.GetLocalPosition();
		box.velocity = transform.GetVelocity();

		return box;
	}

	BoundingBox GetBoundingBox(Matrix transMat) const {
		Matrix temp = coordinateMatrix;
		BoundingBox box;
		box.width = width;
		box.height = height;
		box.postion = temp * transMat * transform.GetLocalPosition();
		box.velocity = transform.GetVelocity();

		return box;
	}

	Matrix GetWorldTransform() {
		return coordinateMatrix * transform.GetLocalTransform();
	}

	Vector GetWorldPosition() {
		return coordinateMatrix * transform.GetLocalPosition();
	}

	string name;
	bool isDrawBox = false;
protected:
	vector<shared_ptr<Drawable2D>> drawableList;
	Transform2D transform;
	double width = 0;
	double height = 0;
	Matrix coordinateMatrix;
};

