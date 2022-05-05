#pragma once
#include "../Math/Vector.h"
#include "../Math/Matrix.h"

class Transform2D
{
public:
	Transform2D();

	void Translate(double x, double y);
	void Translate(Vector vec);
	void Scaling(double x, double y);
	void Rotation(double x, double y);
	void Update(double delta);

#pragma region Getter
	Vector GetPosition() {
		position = transform * position;
		transform = Matrix::Identity();
		return position;
	}

	Vector GetVelocity() const {
		return velocity;
	}

	Matrix GetTransformMatrix() {
		return transform * Matrix::Translation(position);
	}

#pragma endregion

#pragma region Setter
	void SetPosition(Vector vec) {
		position = vec;
		transform = Matrix::Identity();
	}
	void SetVelocity(Vector vec) {
		velocity = vec;
	}
#pragma endregion
private:
	Vector position;
	Vector velocity;
	Matrix transform;
};

