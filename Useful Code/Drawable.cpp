#include "Drawable.h"



Drawable::Drawable()
{
}


Drawable::~Drawable()
{
}

void Drawable::draw(DrawTarget * target, float alpha) const
{
	target->_set_target();
	_draw(target, alpha);
}

