#include "Matrix.h"

Matrix::Matrix()
{
	matrix = vector<vector<double>>(4);
	for (int i = 0; i < 4; i++)
	{
		matrix[i] = vector<double>(4, 0);
	}
}

Matrix Matrix::operator*(const Matrix& mat)
{
	Matrix temp = Matrix();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int k = 0; k < 4; k++)
			{
				double a = matrix[i][j];
				double b = mat.matrix[j][k];
				temp.matrix[i][k] += a * b;
			}
		}
	}
	return temp;
}

Vector Matrix::operator*(const Vector& vec)
{
	Vector temp = Vector::Zero();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			double a = this->matrix[i][j];
			double b = vec._vec[j];
			temp._vec[i] += a * b;
		}
	}
	return temp;
}

Matrix Matrix::Identity()
{
	Matrix temp = Matrix();
	for (int i = 0; i < 4; i++)
	{
		temp.matrix[i][i] = 1;
	}
	return temp;
}

Matrix Matrix::Scaling(Vector vec)
{
	Matrix temp = Matrix::Identity();
	temp.matrix[0][0] = vec.GetValueX();
	temp.matrix[1][1] = vec.GetValueY();
	temp.matrix[2][2] = vec.GetValueZ();

	return temp;
}

Matrix Matrix::Translation(Vector vec)
{
	Matrix temp = Matrix::Identity();
	temp.matrix[0][3] = vec.GetValueX();
	temp.matrix[1][3] = vec.GetValueY();
	temp.matrix[2][3] = vec.GetValueZ();

	return temp;
}

Matrix Matrix::Rotation(Vector vec)
{
	Matrix tempX = RotationX(vec.GetValueX());
	Matrix tempY = RotationY(vec.GetValueY());
	Matrix tempZ = RotationZ(vec.GetValueZ());
	Matrix temp = tempX * tempY * tempZ;
	return temp;
}

Matrix Matrix::RotationX(double x)
{
	Matrix temp = Matrix::Identity();
	temp.matrix[1][1] = cos(x);
	temp.matrix[1][2] = -sin(x);
	temp.matrix[2][1] = sin(x);
	temp.matrix[2][2] = cos(x);

	return temp;
}

Matrix Matrix::RotationY(double y)
{
	Matrix temp = Matrix::Identity();
	temp.matrix[0][0] = cos(y);
	temp.matrix[0][2] = sin(y);
	temp.matrix[2][0] = -sin(y);
	temp.matrix[2][2] = cos(y);

	return temp;
}

Matrix Matrix::RotationZ(double z)
{
	Matrix temp = Matrix::Identity();
	temp.matrix[0][0] = cos(z);
	temp.matrix[0][1] = -sin(z);
	temp.matrix[1][0] = sin(z);
	temp.matrix[1][1] = cos(z);

	return temp;
}

double Matrix::GetValueAt(int r, int c)
{
	if (r < 0 || r >= 4)
	{
		return 0.0;
	}
	if (c < 0 || c >= 4)
	{
		return 0.0;
	}
	return matrix[r][c];
}

void Matrix::SetValueAt(int r, int c, double value)
{
	if (r < 0 || r >= 4)
	{
		return;
	}
	if (c < 0 || c >= 4)
	{
		return;
	}
	matrix[r][c] = value;
}

D3DXMATRIX Matrix::ToDirectxMatrix3D()
{
	D3DXMATRIX matCombined;
	D3DXMatrixIdentity(&matCombined);
	matCombined._11 = matrix[0][0];
	matCombined._12 = matrix[0][1];
	matCombined._13 = matrix[0][2];
	matCombined._14 = matrix[0][3];

	matCombined._21 = matrix[1][0];
	matCombined._22 = matrix[1][1];
	matCombined._23 = matrix[1][2];
	matCombined._24 = matrix[1][3];

	matCombined._31 = matrix[2][0];
	matCombined._32 = matrix[2][1];
	matCombined._33 = matrix[2][2];
	matCombined._34 = matrix[2][3];

	matCombined._41 = matrix[3][0];
	matCombined._42 = matrix[3][1];
	matCombined._43 = matrix[3][2];
	matCombined._44 = matrix[3][3];

	return matCombined;
}
