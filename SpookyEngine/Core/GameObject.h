#pragma once
#include <vector>
#include <memory>
#include "../Math/Transform2D.h"
#include "../Math/Vector.h"
#include "../Graphic/Sprite.h"
#include "../Graphic/Animation.h"

using namespace::std;

class GameObject
{
public:
	GameObject();
	GameObject(const Vector& position);
	GameObject(const Transform2D& transform);

	virtual void Initialize() {};
	virtual void Update(double delta);
	virtual void Render(Matrix transMat);

	void AddSprite(shared_ptr<Sprite> sprite);
	void AddAnimation(shared_ptr<Animation> animation);
	void SetLocalPosition(Vector position);
	Vector GetLocalPosition() const {
		return transform.GetLocalPosition();
	}
	int width = 0;
	int height = 0;

	string name;
	bool isDrawBox = false;
protected:
	vector<shared_ptr<Drawable2D>> drawableList;
	Transform2D transform;
};

