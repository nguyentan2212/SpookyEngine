#pragma once
#include<d3d9.h>
#include "../Math/Transform2D.h"
#include "../Math/Matrix3D.h"

class Camera2D : public Transform2D
{
public:
	Camera2D(double top, double left, double width, double height, double _near, double _far);

	virtual void Update(double delta) {}

	Matrix3D GetProjectionMatrix() const {
		return oProjectionMat;
	}

	Matrix3D GetViewMatrix() const {
		return viewMat;
	}
	void Translate(double x, double y);

protected:
	Matrix3D oProjectionMat, viewMat;
	double width, height, _far, _near;
	Vector3D cameraDirection, cameraRight, cameraUp;
	void CalcProjectionMatrix();
};

