#pragma once
#include "Figure2D.h"
#include "Vector2D.h"
#include <math.h>

template <class NumType = double> class Square :
	public Figure2D<NumType>
{
public:

	Vector2D<NumType> Center;
	NumType HalfSide;


	Square(const Vector2D<NumType> & center, NumType halfSide) : Center(center), HalfSide(halfSide) {}
	~Square() {}

	// Odziedziczono za pośrednictwem elementu Shape2D
	virtual bool IsInside(const Vector2D<NumType>& point) override
	{
		return abs(point.X - Center.X) < HalfSide && abs(point.Y - Center.Y) < HalfSide;
	}
	virtual bool IsOnBorder(const Vector2D<NumType>& point) override
	{
		return abs(point.X - Center.X) == HalfSide && abs(point.Y - Center.Y) == HalfSide;
	}
	virtual bool IsOver(const Vector2D<NumType>& point) override
	{
		return abs(point.X - Center.X) <= HalfSide && abs(point.Y - Center.Y) <= HalfSide;
	}
	virtual NumType GetArea() override
	{
		return HalfSide * HalfSide * 4;
	}
	virtual NumType GetCircumference() override
	{
		return HalfSide * 8;
	}
};

