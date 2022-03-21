#pragma once
#include <vector>
#include "Vector.h"

using namespace::std;

class Matrix
{
public:
#pragma region Constructors
	Matrix();
	Matrix(int r, int c);
	Matrix(int n, bool isIdentity = false);
#pragma endregion

#pragma region Operators
	Matrix operator*(const Matrix& mat);
	Vector operator*(const Vector& vec);
#pragma endregion

	double GetValueAt(int r, int c);
	void SetValueAt(int r, int c, double value);
protected:
	vector<vector<double>> matrix;
	int row, col;
};