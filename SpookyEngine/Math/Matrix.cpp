#include "Matrix.h"

Matrix::Matrix()
{
	matrix = vector<vector<double>>(0);
	row = col = 0;
}

Matrix::Matrix(int r, int c)
{
	row = r;
	col = c;
	matrix = vector<vector<double>>(r);
	for (int i = 0; i < r; i++)
	{
		matrix[i] = vector<double>(c, 0);
	}
}

Matrix::Matrix(int n, bool isIdentity)
{
	row = n;
	col = n;
	matrix = vector<vector<double>>(row);
	for (int i = 0; i < row; i++)
	{
		matrix[i] = vector<double>(col, 0);
		if (isIdentity)
		{
			matrix[i][i] = 1;
		}
	}
}

Matrix Matrix::operator*(const Matrix& mat)
{
	if (this->col != mat.row)
	{
		return Matrix();
	}


	Matrix temp = Matrix(this->row, mat.col);
	for (int j = 0; j < this->col; j++)
	{
		for (int i = 0; i < this->row; i++)
		{
			for (int k = 0; k < mat.col; k++)
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
	if (this->col != vec.GetDimension())
	{
		return Vector();
	}
	Vector temp = Vector(this->row);
	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			double a = this->matrix[i][j];
			double b = vec._vec[j];
			temp._vec[i] += a * b;
		}
	}
	return temp;
}

double Matrix::GetValueAt(int r, int c)
{
	if (r < 0 || r >= row)
	{
		return 0.0;
	}
	if (c < 0 || c >= col)
	{
		return 0.0;
	}
	return matrix[r][c];
}

void Matrix::SetValueAt(int r, int c, double value)
{
	if (r < 0 || r >= row)
	{
		return;
	}
	if (c < 0 || c >= col)
	{
		return;
	}
	matrix[r][c] = value;
}
