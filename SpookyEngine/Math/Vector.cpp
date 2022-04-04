#include "Vector.h"

Vector::Vector()
{
	_vec = vector<double>(4);
	_vec[3] = 1;
}

Vector::Vector(double x, double y, double z)
{
	_vec = vector<double>(4, 0);
	_vec[0] = x;
	_vec[1] = y;
	_vec[2] = z;
	_vec[3] = 1;
}

Vector::Vector(const Vector& vec)
{
	_vec = vector<double>(4, 0);
	for (int i = 0; i < 4; i++) 
	{
		_vec[i] = vec._vec[i];
	}
}

Vector Vector::operator+(const Vector& vec) const
{
	Vector temp = Vector();
	for (int i = 0; i < 4; i++) {
		temp._vec[i] = _vec[i] + vec._vec[i];
	}
	return temp;
}

Vector Vector::operator-(const Vector& vec) const
{
	Vector temp = Vector();
	for (int i = 0; i < 4; i++) {
		temp._vec[i] = _vec[i] - vec._vec[i];
	}
	return temp;
}

Vector Vector::operator*(double n) const
{
	Vector temp = Vector();
	for (int i = 0; i < 4; i++) {
		temp._vec[i] = _vec[i] * n;
	}
	return temp;
}

Vector Vector::operator/(double n) const
{
	Vector temp = Vector();
	for (int i = 0; i < 4; i++) {
		temp._vec[i] = _vec[i] / n;
	}
	return temp;
}

double Vector::Dot(const Vector& vec) const
{
	double result = 0;
	for (int i = 0; i < 4; i++)
	{
		result += _vec[i] * vec._vec[i];
	}
	return result;
}

double Vector::DistanceTo(const Vector& vec) const
{
	Vector temp = Vector();
	for (int i = 0; i < 4; i++) {
		temp._vec[i] = _vec[i] - vec._vec[i];
	}
	return temp.Length();
}

double Vector::LengthSqared() const
{
	double result = 0;
	for (int i = 0; i < 4; i++)
	{
		result += _vec[i] * _vec[i];
	}
	return result;
}

double Vector::Length() const
{
	return sqrt(this->LengthSqared());
}
