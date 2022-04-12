#pragma once
#include <vector>
#include <d3dx9.h>

using namespace::std;

class Matrix;
class Vector
{
public: 
#pragma region Constructors
	Vector();
	Vector(double x, double y, double z = 0);
	Vector(const Vector& vec);
#pragma endregion

#pragma region Operators
	Vector operator+(const Vector& vec) const;
	Vector operator-(const Vector& vec) const;
	Vector operator*(double n) const;
	Vector operator/(double n) const;
#pragma endregion

#pragma region Getters
	double GetValueX() const {
		return _vec[0];
	}
	double GetValueY() const {
		return _vec[1];
	}
	double GetValueZ() const {
		return _vec[2];
	}
#pragma endregion

	double Dot(const Vector& vec) const;
	double DistanceTo(const Vector& vec) const;
	double LengthSqared() const;
	double Length() const;
	D3DXVECTOR3 ToDirectXVector() {
		return D3DXVECTOR3(_vec[0], _vec[1], _vec[2]);
	}
	static Vector Zero() {
		Vector temp = Vector();
		temp._vec[3] = 0;
		return temp;
	}
protected:
	vector<double> _vec;

	friend class Matrix;
};

