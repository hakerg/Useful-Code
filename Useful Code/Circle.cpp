#include "Circle.h"
#include <cmath>

namespace uc
{

	Circle::Circle(const Vector2D<double>& center_, double radius_) : center(center_), radius(radius_) {}

	Circle::Circle(const Vector2D<double>& p1_, const Vector2D<double>& p2_, const Vector2D<double>& p3_) : center(0.0, 0.0), radius(0.0)
	{

		double divider = 2.0 * (p1_.y * p3_.x - p1_.y * p2_.x + p2_.y * p1_.x - p2_.y * p3_.x + p3_.y * p2_.x - p3_.y * p1_.x);

		center.x = (
			p3_.y * (p2_.x * p2_.x + p2_.y * p2_.y - p1_.x * p1_.x - p1_.y * p1_.y) +
			p2_.y * (p1_.x * p1_.x + p1_.y * p1_.y - p3_.x * p3_.x - p3_.y * p3_.y) +
			p1_.y * (p3_.x * p3_.x + p3_.y * p3_.y - p2_.x * p2_.x - p2_.y * p2_.y)
			) / divider;

		center.y = (
			p3_.x * (p1_.x * p1_.x + p1_.y * p1_.y - p2_.x * p2_.x - p2_.y * p2_.y) +
			p2_.x * (p3_.x * p3_.x + p3_.y * p3_.y - p1_.x * p1_.x - p1_.y * p1_.y) +
			p1_.x * (p2_.x * p2_.x + p2_.y * p2_.y - p3_.x * p3_.x - p3_.y * p3_.y)
			) / divider;

		radius = cbrt(Vector2D<double>(center, p1_).length() * Vector2D<double>(center, p2_).length() * Vector2D<double>(center, p3_).length());

	}

	Circle::~Circle() {}

	// Odziedziczono za poœrednictwem elementu Shape2D

	bool Circle::inside(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() < radius; }

	bool Circle::on_border(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() == radius; }

	bool Circle::over(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() <= radius; }

	double Circle::area() const { return PI * radius * radius; }

	double Circle::circumference() const { return _2PI * radius; }

}