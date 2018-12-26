#pragma once
#include <cmath>
#include "Figure2D.h"
#include "Vector2D.h"

template <class _Numeric> class Oblong :
	public Figure2D<_Numeric>
{
public:

	Vector2D<_Numeric> center, half_size;


	Oblong(const Vector2D<_Numeric> & _center, const Vector2D<_Numeric> & _half_size) : center(_center), half_size(_half_size) {}
	virtual ~Oblong() {}


	Vector2D<_Numeric> top_left() const
	{
		return center - half_size;
	}

	Vector2D<_Numeric> BottomRight() const
	{
		return center + half_size;
	}

	Vector2D<_Numeric> Size() const
	{
		return half_size * 2;
	}

	// Odziedziczono za poœrednictwem elementu Shape2D
	virtual bool inside(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) < half_size.x && abs(point.y - center.y) < half_size.y;
	}
	virtual bool on_border(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) == half_size.x && abs(point.y - center.y) == half_size.y;
	}
	virtual bool over(const Vector2D<_Numeric>& point) const override
	{
		return abs(point.x - center.x) <= half_size.x && abs(point.y - center.y) <= half_size.y;
	}
	virtual _Numeric area() const override
	{
		return half_size.x * half_size.y * 4;
	}
	virtual _Numeric circumference() const override
	{
		return half_size.x * 4 + half_size.y * 4;
	}
};

