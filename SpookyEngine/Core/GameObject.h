#pragma once
#include <vector>
#include <memory>
#include "../Math/Transform2D.h"
#include "../Math/Vector3D.h"
#include "../Graphic/Sprite.h"
#include "../Graphic/Animation.h"

using namespace::std;

class GameObject : public Transform2D
{
public:
	GameObject();
	GameObject(const Vector3D& position);
	GameObject(const Transform2D& transform);

	void AddSprite(shared_ptr<Sprite> sprite);
	void AddAnimation(shared_ptr<Animation> animation);
	void Update(double delta);
	void Render(Vector3D camPos);

private:
	vector<shared_ptr<Sprite>> sprites;
	vector<shared_ptr<Animation>> animations;
};

