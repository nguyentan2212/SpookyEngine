#pragma once
#include "Vector.h"

class Vector3D : public Vector
{
public:
#pragma region Constructors
	Vector3D();
	Vector3D(const Vector3D& vec3);
	Vector3D(double x, double y, double z);
	Vector3D(Vector vec);
#pragma endregion

	Vector3D Cross(Vector3D vec3);

	void SetValue(double x, double y, double z);
	void SetValue(Vector3D vec3);

	double GetValueX() const {
		return _vec[0];
	}
	double GetValueY() const {
		return _vec[1];
	}
	double GetValueZ() const {
		return _vec[2];
	}
};

