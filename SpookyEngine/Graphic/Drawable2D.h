#pragma once
#include "../Math/Transform2D.h"

class Drawable2D
{
public:
	Drawable2D();

	virtual void Update(double delta) {}
	virtual void Render(Matrix transMat) = 0;
	virtual void SetZIndex(float index) = 0;

	void SetPosition(Vector vec) {
		transform.SetPosition(vec);
	}

protected:
	Transform2D transform;
	float zIndex = 0;
	Vector renderPosition;
};

