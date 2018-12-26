#pragma once
#include "Vector2D.h"

class Drawable;

class DrawTarget
{
	friend Drawable;

	virtual void _set_target() const = 0;

public:
	DrawTarget()
	{
	}
	virtual ~DrawTarget()
	{
	}

	virtual Vector2D<unsigned> size() const = 0;

	double dimension() const
	{
		return size().quadrature();
	}

	Vector2D<double> to_pixels(const Vector2D<double> & normalized_vector) const
	{
		return normalized_vector * size();
	}
	double to_pixels(double normalized_dimension) const
	{
		return normalized_dimension * dimension();
	}

	Vector2D<double> to_normalized_vector(const Vector2D<double> & pixels) const
	{
		return pixels / size();
	}
	double to_normalized_dimension(double pixels) const
	{
		return pixels / dimension();
	}
};

