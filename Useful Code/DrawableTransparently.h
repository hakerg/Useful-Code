#pragma once
#include "Drawable.h"
class DrawableTransparently :
	public Drawable
{
public:
	DrawableTransparently();
	virtual ~DrawableTransparently();

	virtual void Draw(DrawTarget * target, float alpha) const = 0;

	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void Draw(DrawTarget * target) const override;
};

