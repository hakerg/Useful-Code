#include "Animatable.h"



Animatable::Animatable()
{
}


Animatable::~Animatable()
{
}

std::shared_ptr<Animatable> Animatable::GetNullFrame()
{
	return std::shared_ptr<Animatable>();
}
