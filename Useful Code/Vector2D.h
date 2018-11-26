#pragma once
#include <math.h>

template <class NumType = double> class Vector2D
{
public:

	NumType X, Y;


	Vector2D(NumType x, NumType y) : X(x), Y(y) {}
	Vector2D(const Vector2D<NumType> & from, const Vector2D<NumType> & to) : X(to.X - from.X), Y(to.Y - from.Y) {}
	virtual ~Vector2D() {}

	static Vector2D<NumType> FromPolar(NumType length, NumType rotation)
	{
		return Vector2D<NumType>(length * cos(rotation), length * sin(rotation));
	}

	NumType GetLength() const { return sqrt(X * X + Y * Y); }
	NumType GetRotation() const { return atan2(Y, X); }


	Vector2D<NumType> GetRotated(NumType rotation) const
	{
		NumType sinA = sin(rotation);
		NumType cosA = cos(rotation);
		return Vector2D<NumType>(X * cosA - Y * sinA, X * sinA + Y * cosA);
	}


	bool operator == (const Vector2D<NumType> & b) const
	{
		return X == b.X && Y == b.Y;
	}

	Vector2D<NumType> operator + (const Vector2D<NumType> & b) const
	{
		return Vector2D<NumType>(X + b.X, Y + b.Y);
	}

	Vector2D<NumType> operator - (const Vector2D<NumType> & b) const
	{
		return Vector2D<NumType>(X - b.X, Y - b.Y);
	}

	Vector2D<NumType> operator * (NumType b) const
	{
		return Vector2D<NumType>(X * b, Y * b);
	}

	Vector2D<NumType> operator * (const Vector2D<NumType> & b) const
	{
		return Vector2D<NumType>(X * b.X, Y * b.Y);
	}

	Vector2D<NumType> operator / (NumType b) const
	{
		return Vector2D<NumType>(X / b, Y / b);
	}
}; 

