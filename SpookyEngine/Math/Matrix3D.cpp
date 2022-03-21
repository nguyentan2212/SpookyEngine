#include "Matrix3D.h"

Matrix3D::Matrix3D(Matrix mat) : Matrix(4)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matrix[i][j] = mat.GetValueAt(i,j);
        }
    }
}

Matrix3D Matrix3D::Scaling(Vector3D vec3)
{
    Matrix3D temp = Matrix3D(true);
    temp.matrix[0][0] = vec3.GetValueX();
    temp.matrix[1][1] = vec3.GetValueY();
    temp.matrix[2][2] = vec3.GetValueZ();

    return temp;
}

Matrix3D Matrix3D::Translation(Vector3D vec3)
{
    Matrix3D temp = Matrix3D(true);
    temp.matrix[0][3] = vec3.GetValueX();
    temp.matrix[1][3] = vec3.GetValueY();
    temp.matrix[2][3] = vec3.GetValueZ();

    return temp;
}

Matrix3D Matrix3D::Rotation(Vector3D vec3)
{
    Matrix3D tempX = RotationX(vec3.GetValueX());
    Matrix3D tempY = RotationY(vec3.GetValueY());
    Matrix3D tempZ = RotationZ(vec3.GetValueZ());
    Matrix temp = tempX * tempY * tempZ;
    return Matrix3D(temp);
}

Matrix3D Matrix3D::RotationX(double x)
{
    Matrix3D temp = Matrix3D(true);
    temp.matrix[1][1] = cos(x);
    temp.matrix[1][2] = -sin(x);
    temp.matrix[2][1] = sin(x);
    temp.matrix[2][2] = cos(x);

    return temp;
}

Matrix3D Matrix3D::RotationY(double y)
{
    Matrix3D temp = Matrix3D(true);
    temp.matrix[0][0] = cos(y);
    temp.matrix[0][2] = sin(y);
    temp.matrix[2][0] = -sin(y);
    temp.matrix[2][2] = cos(y);

    return temp;
}

Matrix3D Matrix3D::RotationZ(double z)
{
    Matrix3D temp = Matrix3D(true);
    temp.matrix[0][0] = cos(z);
    temp.matrix[0][1] = -sin(z);
    temp.matrix[1][0] = sin(z);
    temp.matrix[1][1] = cos(z);

    return temp;
}

D3DXMATRIX Matrix3D::ToDirectxMatrix3D(Matrix3D mat)
{
    D3DXMATRIX matCombined;
    D3DXMatrixIdentity(&matCombined);
    matCombined._11 = mat.GetValueAt(0, 0);
    matCombined._12 = mat.GetValueAt(0, 1);
    matCombined._13 = mat.GetValueAt(0, 2);
    matCombined._14 = mat.GetValueAt(0, 3);

    matCombined._21 = mat.GetValueAt(1, 0);
    matCombined._22 = mat.GetValueAt(1, 1);
    matCombined._23 = mat.GetValueAt(1, 2);
    matCombined._24 = mat.GetValueAt(1, 3);

    matCombined._31 = mat.GetValueAt(2, 0);
    matCombined._32 = mat.GetValueAt(2, 1);
    matCombined._33 = mat.GetValueAt(2, 2);
    matCombined._34 = mat.GetValueAt(2, 3);

    matCombined._41 = mat.GetValueAt(3, 0);
    matCombined._42 = mat.GetValueAt(3, 1);
    matCombined._43 = mat.GetValueAt(3, 2);
    matCombined._44 = mat.GetValueAt(3, 3);

    return matCombined;
}