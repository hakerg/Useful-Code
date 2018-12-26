#pragma once
#include "Vector2D.h"

template <class _Numeric> class Figure2D
{
public:
	Figure2D() {}
	virtual ~Figure2D() {}

	virtual bool inside(const Vector2D<_Numeric> & point) const = 0;
	virtual bool on_border(const Vector2D<_Numeric> & point) const = 0;
	virtual bool over(const Vector2D<_Numeric> & point) const = 0;

	virtual _Numeric area() const = 0;
	virtual _Numeric circumference() const = 0;
};

