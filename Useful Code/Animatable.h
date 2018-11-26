#pragma once
#include "Drawable.h"
#include <memory>

class Animatable :
	public Drawable
{
public:

	Animatable();
	virtual ~Animatable();
	
	virtual std::shared_ptr<Animatable> GetNextFrame() const = 0; // return null frame if no frame
	static std::shared_ptr<Animatable> GetNullFrame();
};

