#pragma once
#include <allegro5\allegro.h>
#include "Image.h"
#include "Vector2D.h"

class AllegroBitmap :
	public Image
{
	// Odziedziczono za poœrednictwem elementu Image
	virtual void _draw(DrawTarget * target, float alpha) const override;

	virtual void _set_target() const override;

public:

	ALLEGRO_BITMAP * const k_bitmap;
	Vector2D<float> position;

	AllegroBitmap(const Vector2D<unsigned>& _size);
	virtual ~AllegroBitmap();

	// Odziedziczono za poœrednictwem elementu Image
	virtual Vector2D<unsigned> size() const override;
};

