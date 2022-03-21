#pragma once
#include "../Math/Vector3D.h"
#include "../Math/Matrix3D.h"

class Transform2D
{
public:
	Transform2D();

	virtual void Translate(double x, double y);
	void Scaling(double x, double y);
	void Rotation(double x, double y);

#pragma region Getter
	Vector3D GetPosition() const {
		return position;
	}
	Vector3D GetLocalPosition() const {
		Vector3D temp = GetTransform() * position;
		return temp;
	}
	Matrix3D GetTransform() const {
		return transform;
	}
	Matrix3D GetLocalTransform() const {
		Matrix3D temp = GetTransform() * Matrix3D::Translation(position);
		return temp;
	}
#pragma endregion

#pragma region Setter
	void SetLocalPosition(Vector3D vec) {
		position = vec;
		transform = Matrix3D(true);
	}
#pragma endregion
private:
	Vector3D position;
	Matrix3D transform;
};

