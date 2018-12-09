#include "DrawableTransparently.h"



DrawableTransparently::DrawableTransparently()
{
}


DrawableTransparently::~DrawableTransparently()
{
}

void DrawableTransparently::Draw(DrawTarget * target) const
{
	Draw(target, 1.0f);
}
