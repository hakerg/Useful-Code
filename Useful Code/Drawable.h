#pragma once
#include "DrawTarget.h"

class Drawable
{
public:
	Drawable();
	virtual ~Drawable();

	virtual void Draw(DrawTarget * target) const = 0;
};

