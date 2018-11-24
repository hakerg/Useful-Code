#pragma once
#include <math.h>

template <class NumType = double> class Vector3D
{
public:

	NumType X, Y, Z;


	Vector3D(NumType x, NumType y, NumType z) : X(x), Y(y), Z(z) {}
	Vector3D(const Vector3D<NumType> & from, const Vector3D<NumType> & to) : X(to.X - from.X), Y(to.Y - from.Y), Z(to.Z - from.Z) {}
	~Vector3D() {}

	static Vector3D<NumType> FromCylindrical(NumType radius, NumType azimuthalRotation, NumType z)
	{
		return Vector3D<NumType>(radius * cos(azimuthalRotation), radius * sin(azimuthalRotation), z);
	}

	static Vector3D<NumType> FromSpherical(NumType radius, NumType azimuthalRotation, NumType polarRotation)
	{
		NumType radiusSinPolar = radius * sin(polarRotation);
		return Vector3D<NumType>(radiusSinPolar * cos(azimuthalRotation), radiusSinPolar * sin(azimuthalRotation), radius * cos(polarRotation));
	}

	NumType GetLength() { return sqrt(X * X + Y * Y + Z * Z); }
	NumType GetAzimuthalRotation() { return atan2(Y, X); }
	NumType GetPolarRotation() { return acos(Z / GetLength()); }


	Vector3D<NumType> GetRotatedZ(NumType rotation)
	{
		NumType sinA = sin(rotation);
		NumType cosA = cos(rotation);
		return Vector3D<NumType>(X * cosA - Y * sinA, X * sinA + Y * cosA, Z);
	}

	Vector3D<NumType> GetRotatedY(NumType rotation)
	{
		NumType sinA = sin(rotation);
		NumType cosA = cos(rotation);
		return Vector3D<NumType>(X * cosA + Z * sinA, Y, Z * cosA - X * sinA);
	}

	Vector3D<NumType> GetRotatedX(NumType rotation)
	{
		NumType sinA = sin(rotation);
		NumType cosA = cos(rotation);
		return Vector3D<NumType>(X, Y * cosA - Z * sinA, Y * sinA + Z * cosA);
	}


	bool operator == (const Vector3D<NumType> & b)
	{
		return X == b.X && Y == b.Y && Z == b.Z;
	}

	Vector3D<NumType> operator + (const Vector3D<NumType> & b)
	{
		return Vector3D<NumType>(X + b.X, Y + b.Y, Z + b.Z);
	}

	Vector3D<NumType> operator - (const Vector3D<NumType> & b)
	{
		return Vector3D<NumType>(X - b.X, Y - b.Y, Z - b.Z);
	}

	Vector3D<NumType> operator * (NumType b)
	{
		return Vector3D<NumType>(X * b, Y * b, Z * b);
	}

	Vector3D<NumType> operator * (const Vector3D<NumType> & b)
	{
		return Vector3D<NumType>(X * b.X, Y * b.Y, Z * b.Z);
	}

	Vector3D<NumType> operator / (NumType b)
	{
		return Vector3D<NumType>(X / b, Y / b, Z / b);
	}
};

