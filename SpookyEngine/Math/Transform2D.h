#pragma once
#include "../Math/Vector.h"
#include "../Math/Matrix.h"

class Transform2D
{
public:
	Transform2D();

	virtual void Translate(double x, double y);
	void Scaling(double x, double y);
	void Rotation(double x, double y);

#pragma region Getter
	Vector GetPosition() const {
		return position;
	}
	Vector GetLocalPosition() const {
		Vector temp = GetTransform() * position;
		return temp;
	}
	Matrix GetTransform() const {
		return transform;
	}
	Matrix GetLocalTransform() const {
		Matrix temp = GetTransform() * Matrix::Translation(position);
		return temp;
	}
#pragma endregion

#pragma region Setter
	void SetLocalPosition(Vector vec) {
		position = vec;
		transform = Matrix::Identity();
	}
#pragma endregion
private:
	Vector position;
	Matrix transform;
};

