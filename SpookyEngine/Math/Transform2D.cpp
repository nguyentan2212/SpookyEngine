#include "Transform2D.h"

Transform2D::Transform2D()
{
	position = Vector();
	transform = Matrix::Identity();
}

void Transform2D::Translate(double x, double y)
{
	transform = transform * Matrix::Translation(Vector(x, y));
}

void Transform2D::Scaling(double x, double y)
{
	transform = transform * Matrix::Scaling(Vector(x, y));
}

void Transform2D::Rotation(double x, double y)
{
	transform = transform * Matrix::Rotation(Vector(x, y));
}
