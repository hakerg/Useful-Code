#pragma once
#include "Figure2D.h"
#include "Vector2D.h"
#include <math.h>

template <class NumType = double> class Rectangle :
	public Figure2D<NumType>
{
public:

	Vector2D<NumType> Center, HalfDiagonal;


	Rectangle(const Vector2D<NumType> & center, const Vector2D<NumType> & halfDiagonal) : Center(center), HalfDiagonal(halfDiagonal) {}
	virtual ~Rectangle() {}

	// Odziedziczono za poœrednictwem elementu Shape2D
	virtual bool IsInside(const Vector2D<NumType>& point) const override
	{
		return abs(point.X - Center.X) < HalfDiagonal.X && abs(point.Y - Center.Y) < HalfDiagonal.Y;
	}
	virtual bool IsOnBorder(const Vector2D<NumType>& point) const override
	{
		return abs(point.X - Center.X) == HalfDiagonal.X && abs(point.Y - Center.Y) == HalfDiagonal.Y;
	}
	virtual bool IsOver(const Vector2D<NumType>& point) const override
	{
		return abs(point.X - Center.X) <= HalfDiagonal.X && abs(point.Y - Center.Y) <= HalfDiagonal.Y;
	}
	virtual NumType GetArea() const override
	{
		return HalfDiagonal.X * HalfDiagonal.Y * 4;
	}
	virtual NumType GetCircumference() const override
	{
		return HalfDiagonal.X * 4 + HalfDiagonal.Y * 4;
	}
};

