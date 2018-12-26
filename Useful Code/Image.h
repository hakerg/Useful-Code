#pragma once
#include "Drawable.h"
#include "DrawTarget.h"

class Image :
	public Drawable, public DrawTarget
{
public:
	Image();
	virtual ~Image();
};

