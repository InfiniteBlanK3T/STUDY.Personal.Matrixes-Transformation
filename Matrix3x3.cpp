#include "Matrix3x3.h"

Matrix3x3::Matrix3x3() noexcept :
	fRows{(1.0f, 0.0f, 0.0f), (0.0f, 1.0f, 0.0f), (0.0f, 0.0f, 1.0f) }
{}
Matrix3x3::Matrix3x3(const Vector3D& aRow1, const Vector3D& aRow2, const Vector3D& aRow3) noexcept:
	fRows{ aRow1, aRow2, aRow3 }
{}

