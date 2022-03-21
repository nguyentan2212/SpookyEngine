#include "Vector3D.h"

Vector3D::Vector3D() : Vector(4)
{
	_vec[3] = 1;
}

Vector3D::Vector3D(const Vector3D& vec3) : Vector(vec3)
{
	_vec[3] = 1;
}

Vector3D::Vector3D(double x, double y, double z) : Vector(4)
{
	_vec[0] = x;
	_vec[1] = y;
	_vec[2] = z;
	_vec[3] = 1;
}

Vector3D::Vector3D(Vector vec) : Vector(4)
{
	_vec[0] = vec.GetValueAt(0);
	_vec[1] = vec.GetValueAt(1);
	_vec[2] = vec.GetValueAt(2);
	_vec[3] = 1;
}

Vector3D Vector3D::Cross(Vector3D vec3)
{
	double tempX = _vec[1] * vec3._vec[2] - _vec[2] * vec3._vec[1];
	double tempY = _vec[2] * vec3._vec[0] - _vec[0] * vec3._vec[2];
	double tempZ = _vec[0] * vec3._vec[1] - _vec[1] * vec3._vec[0];
	return Vector3D(tempX, tempY, tempZ);
}

void Vector3D::SetValue(double x, double y, double z)
{
	_vec[0] = x;
	_vec[1] = y;
	_vec[2] = z;
}

void Vector3D::SetValue(Vector3D vec3)
{
	SetValue(vec3._vec[0], vec3._vec[1], vec3._vec[2]);
}
