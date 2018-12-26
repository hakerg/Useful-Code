#pragma once
#include "Figure2D.h"
#include "math_defines.h"
#include "Vector2D.h"

class Circle :
	public Figure2D<double>
{
public:

	Vector2D<double> center;
	double radius;


	Circle(const Vector2D<double> & _center, double _radius);
	virtual ~Circle();

	// Odziedziczono za poœrednictwem elementu Shape2D
	virtual bool inside(const Vector2D<double>& point) const override;
	virtual bool on_border(const Vector2D<double>& point) const override;
	virtual bool over(const Vector2D<double>& point) const override;

	virtual double area() const override;
	virtual double circumference() const override;
};

