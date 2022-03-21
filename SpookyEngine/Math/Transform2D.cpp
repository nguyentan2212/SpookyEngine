#include "Transform2D.h"

Transform2D::Transform2D()
{
	position = Vector3D();
	transform = Matrix3D(true);
}

void Transform2D::Translate(double x, double y)
{
	transform = transform * Matrix3D::Translation(Vector3D(x, y, 0));
}

void Transform2D::Scaling(double x, double y)
{
	transform = transform * Matrix3D::Scaling(Vector3D(x, y, 1));
}

void Transform2D::Rotation(double x, double y)
{
	transform = transform * Matrix3D::Rotation(Vector3D(x, y, 0));
}
