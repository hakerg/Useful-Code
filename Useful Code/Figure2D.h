#pragma once
#include "Vector2D.h"

template <class NumType = double> class Figure2D
{
public:
	Figure2D() {}
	~Figure2D() {}

	virtual bool IsInside(const Vector2D<NumType> & point) = 0;
	virtual bool IsOnBorder(const Vector2D<NumType> & point) = 0;
	virtual bool IsOver(const Vector2D<NumType> & point) = 0;

	virtual NumType GetArea() = 0;
	virtual NumType GetCircumference() = 0;
};

