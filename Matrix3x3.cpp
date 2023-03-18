#include "Matrix3x3.h"
#include <cmath>
#include <math.h>
#include <cassert>
#define PI 3.14159265f


Matrix3x3::Matrix3x3() noexcept :
	fRows{ (1, 0, 0), (0, 1, 0), (0, 0, 1) }
{}

Matrix3x3::Matrix3x3(const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3) noexcept:	
	fRows{ aRow1, aRow2, aRow3 }	
{}

Matrix3x3 Matrix3x3::operator*(const float aScalar) const noexcept
{
	return Matrix3x3( row(0) * aScalar, row(1) * aScalar, row(2) * aScalar );
}

Matrix3x3 Matrix3x3::operator+(const Matrix3x3& aOther) const noexcept
{
	return Matrix3x3( 
		row(0) + aOther.row(0),
		row(1) + aOther.row(1),
		row(2) + aOther.row(2)
	);
}

Vector3D Matrix3x3::operator*(const Vector3D& aVector) const noexcept
{
	return Vector3D( row(0).dot(aVector), row(1).dot(aVector), row(2).dot(aVector) );
}

Matrix3x3 Matrix3x3::scale(const float aX, const float aY)
{
	return Matrix3x3( { aX, 0, 0 }, { 0, aY, 0 }, {0, 0, 1} );
}

Matrix3x3 Matrix3x3::translate(const float aX, const float aY)
{
	return Matrix3x3( { 1, 0, aX }, { 0, 1, aY }, { 0, 0, 1 } );
}

Matrix3x3 Matrix3x3::rotate(const float aAngleInDegree)
{
	return Matrix3x3(
		{ cos(aAngleInDegree * PI / 180.0f), -sin(aAngleInDegree * PI / 180.0f), 0.0f },
		{ sin(aAngleInDegree * PI / 180.0f), cos(aAngleInDegree * PI / 180.0f), 0.0f },
		{ 0.0f, 0.0f, 1 }
	);
}

const Vector3D Matrix3x3::row( size_t aRowIndex ) const
{
	assert(aRowIndex < 3);

	return Vector3D( fRows[aRowIndex] );
}

const Vector3D Matrix3x3::column(size_t aColumnIndex) const
{
	assert( aColumnIndex < 3 );

	return Vector3D(row(0)[aColumnIndex], row(1)[aColumnIndex], row(2)[aColumnIndex]);
}


