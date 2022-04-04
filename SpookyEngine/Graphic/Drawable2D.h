#pragma once
#include "../Math/Transform2D.h"

class Drawable2D
{
public:
	Drawable2D();

	virtual void Update(double delta) {}
	virtual void Render(Matrix transMat) = 0;

	void SetLocalPosition(Vector vec) {
		transform.SetLocalPosition(vec);
	}

	void SetRenderPosition(Vector vec) {
		renderPosition = vec;
	}

	Vector GetRenderPosition() const {
		return renderPosition;
	}
protected:
	Transform2D transform;
	int z_index = 0;
	Vector renderPosition;
};

