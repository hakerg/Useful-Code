#pragma once
#include "Figure2D.h"
#include "Vector2D.h"

constexpr auto Pi = 3.1415926535897932384626433832795;
constexpr auto Pi2 = 6.283185307179586476925286766559;

template <class NumType = double> class Circle :
	public Figure2D<NumType>
{
public:

	Vector2D<NumType> Center;
	double Radius;


	Circle(const Vector2D<NumType> & center, double radius) : Center(center), Radius(radius) {}
	virtual ~Circle() {}

	// Odziedziczono za pośrednictwem elementu Shape2D
	virtual bool IsInside(const Vector2D<NumType>& point) const override { return Vector2D<NumType>(Center, point).GetLength() < Radius; }
	virtual bool IsOnBorder(const Vector2D<NumType>& point) const override { return Vector2D<NumType>(Center, point).GetLength() == Radius; }
	virtual bool IsOver(const Vector2D<NumType>& point) const override { return Vector2D<NumType>(Center, point).GetLength() <= Radius; }

	virtual NumType GetArea() const override { return Pi * Radius * Radius; }
	virtual NumType GetCircumference() const override { Pi2 * Radius; }
};

