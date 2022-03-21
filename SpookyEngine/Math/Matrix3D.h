#pragma once
#include "Matrix.h"
#include "Vector3D.h"
#include <d3dx9.h>

class Matrix3D : public Matrix
{
public:
	Matrix3D(bool isIdentity = false) : Matrix(4, isIdentity) {}
	Matrix3D(Matrix mat);

	static Matrix3D Scaling(Vector3D vec3);
	static Matrix3D Translation(Vector3D vec3);
	static Matrix3D Rotation(Vector3D vec3);

	static Matrix3D RotationX(double x);
	static Matrix3D RotationY(double y);
	static Matrix3D RotationZ(double z);

	static D3DXMATRIX ToDirectxMatrix3D(Matrix3D mat);
private:
	
};

