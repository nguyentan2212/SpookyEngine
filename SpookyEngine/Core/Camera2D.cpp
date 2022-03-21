#include "Camera2D.h"

Camera2D::Camera2D(double top, double left, double width, double height, double _near, double _far)
{
	SetLocalPosition(Vector3D(left, top, 0));
	this->width = width;
	this->height = height;
	this->_far = _far;
	this->_near = _near;

	oProjectionMat = Matrix3D(true);
	CalcProjectionMatrix();
}

void Camera2D::Translate(double x, double y)
{
	Transform2D::Translate(x, y);
	CalcProjectionMatrix();
}

void Camera2D::CalcProjectionMatrix()
{
	Vector3D pos = GetLocalPosition();
	double left = pos.GetValueX();
	double top = pos.GetValueY();
	double bottom = top + height;
	double right = left + width;

	oProjectionMat.SetValueAt(0, 0, 2 / (right - left));
	oProjectionMat.SetValueAt(1, 1, 2 / (top - bottom));
	// oProjectionMat.SetValueAt(2, 2, -2 / (_far - _near));

	oProjectionMat.SetValueAt(0, 3, -(right + left) / (right - left));
	oProjectionMat.SetValueAt(1, 3, -(top + bottom) / (top - bottom));
	// oProjectionMat.SetValueAt(2, 3, -(_far + _near) / (_far - _near));
}
