#pragma once
#include "Vector2D.h"

template <class NumType = double> class Figure2D
{
public:
	Figure2D() {}
	virtual ~Figure2D() {}

	virtual bool IsInside(const Vector2D<NumType> & point) const = 0;
	virtual bool IsOnBorder(const Vector2D<NumType> & point) const = 0;
	virtual bool IsOver(const Vector2D<NumType> & point) const = 0;

	virtual NumType GetArea() const = 0;
	virtual NumType GetCircumference() const = 0;
};

