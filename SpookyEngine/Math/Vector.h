#pragma once
#include <vector>
using namespace::std;

class Matrix;
class Vector
{
public: 
#pragma region Constructors
	Vector();
	Vector(int dim);
	Vector(const Vector& vec);
#pragma endregion

#pragma region Operators
	Vector operator+(const Vector& vec) const;
	Vector operator-(const Vector& vec) const;
	Vector operator*(double n) const;
	Vector operator/(double n) const;
#pragma endregion

	double Dot(const Vector& vec) const;
	double DistanceTo(const Vector& vec) const;
	double LengthSqared() const;
	double Length() const;
	int GetDimension() const {
		return dimension;
	}
	static Vector Normalize(Vector vec) {
		double len = vec.Length();
		Vector temp = Vector(vec);
		temp = temp / len;
		return temp;
	}

	double GetValueAt(int n);

protected:
	vector<double> _vec;
	int dimension;

	friend class Matrix;
};

