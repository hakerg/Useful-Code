#include "Circle.h"

Circle::Circle(const Vector2D<double>& _center, double _radius) : center(_center), radius(_radius) {}

Circle::~Circle() {}

// Odziedziczono za poœrednictwem elementu Shape2D

bool Circle::inside(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() < radius; }

bool Circle::on_border(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() == radius; }

bool Circle::over(const Vector2D<double>& point) const { return Vector2D<double>(center, point).length() <= radius; }

double Circle::area() const { return PI * radius * radius; }

double Circle::circumference() const { return _2PI * radius; }
