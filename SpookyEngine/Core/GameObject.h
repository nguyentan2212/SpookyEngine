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

#define LEFT 0
#define RIGHT 1

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
	void SetPosition(Vector position);
	void SetVelocity(Vector velocity);

	Vector GetPosition() {
		return transform.GetPosition();
	}
	BoundingBox GetBoundingBox(double delta = 1) {
		BoundingBox box;
		box.width = width;
		box.height = height;
		box.position = transform.GetPosition();
		box.velocity = transform.GetVelocity() * delta;

		return box;
	}

	void Destroy() {
		isDestroyed = true;
	}
	bool IsDestroyed() const {
		return isDestroyed;
	}

	string name;
	bool isDrawBox = false;
protected:
	vector<shared_ptr<Drawable2D>> drawableList;
	Transform2D transform;
	double width = 0;
	double height = 0;
	bool isDestroyed = false;
};

