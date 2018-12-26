#include "AllegroBitmap.h"



AllegroBitmap::AllegroBitmap(const Vector2D<unsigned>& _size) : k_bitmap(al_create_bitmap(_size.x, _size.y)), position(0.0f, 0.0f)
{
}


AllegroBitmap::~AllegroBitmap()
{
	al_destroy_bitmap(k_bitmap);
}

void AllegroBitmap::_draw(DrawTarget * target, float alpha) const
{
	al_draw_tinted_bitmap(k_bitmap, al_map_rgba_f(alpha, alpha, alpha, alpha), position.x, position.y, NULL);
}

void AllegroBitmap::_set_target() const
{
	al_set_target_bitmap(k_bitmap);
}

Vector2D<unsigned> AllegroBitmap::size() const
{
	return Vector2D<unsigned>(al_get_bitmap_width(k_bitmap), al_get_bitmap_height(k_bitmap));
}
