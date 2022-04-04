#pragma once
#include <vector>
#include "Vector.h"
#include <d3dx9.h>

using namespace::std;

class Matrix
{
public:
#pragma region Constructors
	Matrix();
#pragma endregion

#pragma region Operators
	Matrix operator*(const Matrix& mat);
	Vector operator*(const Vector& vec);
#pragma endregion

#pragma region Static Matrix Instances
	static Matrix Identity();
	static Matrix Scaling(Vector vec);
	static Matrix Translation(Vector vec);
	static Matrix Rotation(Vector vec);

	static Matrix RotationX(double x);
	static Matrix RotationY(double y);
	static Matrix RotationZ(double z);
#pragma endregion
	double GetValueAt(int r, int c);
	void SetValueAt(int r, int c, double value);
	D3DXMATRIX ToDirectxMatrix3D();
protected:
	vector<vector<double>> matrix;
};