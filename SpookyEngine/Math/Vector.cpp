#include "Vector.h"

Vector::Vector()
{
	dimension = 0;
	_vec = vector<double>(0);
}

Vector::Vector(int dim)
{
	dimension = dim;
	_vec = vector<double>(dim, 0);
}

Vector::Vector(const Vector& vec)
{
	dimension = vec.dimension;
	_vec = vector<double>(dimension, 0);
	for (int i = 0; i < dimension; i++) 
	{
		_vec[i] = vec._vec[i];
	}
}

Vector Vector::operator+(const Vector& vec) const
{
	if (dimension != vec.dimension)
	{
		return Vector();
	}

	Vector temp = Vector(dimension);
	for (int i = 0; i < dimension; i++) {
		temp._vec[i] = _vec[i] + vec._vec[i];
	}
	return temp;
}

Vector Vector::operator-(const Vector& vec) const
{
	if (dimension != vec.dimension)
	{
		return Vector();
	}

	Vector temp = Vector(dimension);
	for (int i = 0; i < dimension; i++) {
		temp._vec[i] = _vec[i] - vec._vec[i];
	}
	return temp;
}

Vector Vector::operator*(double n) const
{
	Vector temp = Vector(dimension);
	for (int i = 0; i < dimension; i++) {
		temp._vec[i] = _vec[i] * n;
	}
	return temp;
}

Vector Vector::operator/(double n) const
{
	Vector temp = Vector(dimension);
	for (int i = 0; i < dimension; i++) {
		temp._vec[i] = _vec[i] / n;
	}
	return temp;
}

double Vector::Dot(const Vector& vec) const
{
	if (dimension != vec.dimension)
	{
		return 0.0;
	}

	double result = 0;
	for (int i = 0; i < dimension; i++)
	{
		result += _vec[i] * vec._vec[i];
	}
	return result;
}

double Vector::DistanceTo(const Vector& vec) const
{
	if (dimension != vec.dimension)
	{
		return 0.0;
	}

	Vector temp = Vector(dimension);
	for (int i = 0; i < dimension; i++) {
		temp._vec[i] = _vec[i] - vec._vec[i];
	}
	return temp.Length();
}

double Vector::LengthSqared() const
{
	double result = 0;
	for (int i = 0; i < dimension; i++)
	{
		result += _vec[i] * _vec[i];
	}
	return result;
}

double Vector::Length() const
{
	return sqrt(this->LengthSqared());
}

double Vector::GetValueAt(int n)
{
	if (n < 0 || n > dimension)
	{
		return 0.0;
	}
	return _vec[n];
}
