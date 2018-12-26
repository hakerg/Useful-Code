#pragma once
#include <cmath>
#include "Figure2D.h"
#include "Vector2D.h"

template <class _Numeric> class Square :
	public Figure2D<_Numeric>
{
public:

	Vector2D<_Numeric> center;
	_Numeric half_side;


	Square(const Vector2D<_Numeric> & _center, _Numeric _half_side) : center(_center), half_side(_half_side) {}
	virtual ~Square() {}

	Vector2D<_Numeric> top_left() const
	{
		return Vector2D<_Numeric>(center.x - half_side, center.y - half_side);
	}

	Vector2D<_Numeric> bottom_right() const
	{
		return Vector2D<_Numeric>(center.x + half_side, center.y + half_side);
	}

	_Numeric side() const
	{
		return 2 * half_side;
	}

	// Odziedziczono za poœrednictwem elementu Shape2D
	virtual bool inside(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) < half_side && abs(point.y - center.y) < half_side;
	}
	virtual bool on_border(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) == half_side && abs(point.y - center.y) == half_side;
	}
	virtual bool over(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) <= half_side && abs(point.y - center.y) <= half_side;
	}
	virtual _Numeric area() const override
	{
		return half_side * half_side * 4;
	}
	virtual _Numeric circumference() const override
	{
		return half_side * 8;
	}
};

