#include "AnimationExponential.h"
#include <cmath>



AnimationExponential::AnimationExponential(double & _value, double _factor, double _target_value)
	: value(_value), factor(_factor), target_value(_target_value)
{
}


AnimationExponential::~AnimationExponential()
{
}

bool AnimationExponential::add_time(std::chrono::duration<double> delta_time)
{
	value = target_value + (value - target_value) * exp(-delta_time.count() * factor);
	return true;
}
