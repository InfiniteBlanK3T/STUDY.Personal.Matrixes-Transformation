#include "Matrix3x3.h"
#include <cmath>


Matrix3x3::Matrix3x3() noexcept :
	fRows{ (1.0f, 0.0f, 0.0f), (0.0f, 1.0f, 0.0f), (0.0f, 0.0f, 1.0f) }
{}

Matrix3x3::Matrix3x3(const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3) noexcept:
	fRows{ aRow1, aRow2, aRow3 }	
{}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept
{
	return Matrix3x3(row(0) * aScalar, row(1) * aScalar, row(2) * aScalar);
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& aOther) const noexcept
{
	return Matrix3x3(row(0) + aOther.row(0), row(1) + aOther.row(1), row(2) + aOther.row(2));
}

Vector3D Matrix3x3::operator*(const Vector3D& aVector) const noexcept
{
	return Vector3D(row(0).dot(aVector) * row(1).dot(aVector) * row(2).dot(aVector));
}

Matrix3x3 Matrix3x3::scale(const float aX, const float aY)
{
	return Matrix3x3((aX, 0.0f, 0.0f), (0.0f, aY, 0.0f), (0.0f, 0.0f, 1));	
}

Matrix3x3 Matrix3x3::translate(const float aX, const float aY)
{
	return Matrix3x3((1, 0.0f, aX), (0.0f, 1.0f, aY), (0.0f, 0.0f, 1));	
}

Matrix3x3 Matrix3x3::rotate(const float aAngleInDegree)
{
	return Matrix3x3((cos(aAngleInDegree), -sin(aAngleInDegree), 0.0f), (sin(aAngleInDegree), cos(aAngleInDegree), 0.0f), (0.0f, 0.0f, 1));
}

Vector3D const Matrix3x3::row( size_t aRowIndex ) const
{
	return Vector3D(fRows[aRowIndex]);
}

Vector3D const Matrix3x3::column(size_t aColumnIndex) const
{
	return Vector3D(fRows[0][aColumnIndex], fRows[1][aColumnIndex], fRows[2][aColumnIndex]);
}


