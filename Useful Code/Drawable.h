#pragma once
#include "DrawTarget.h"

class Drawable
{

	virtual void _draw(DrawTarget * target, float alpha) const = 0;

public:
	Drawable();
	virtual ~Drawable();

	void draw(DrawTarget * target, float alpha = 1.0f) const;
};

