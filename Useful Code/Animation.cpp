#include "Animation.h"



Animation::Animation()
{
}


Animation::~Animation()
{
}


double Animation::GetQuarterSine(double startValue, double targetOffset, double time)
{
	return startValue + targetOffset * sin(time * PI_2);
}

double Animation::GetHalfCosine(double startValue, double targetOffset, double time)
{
	return startValue + targetOffset * (1.0 - cos(time * PI)) * 0.5;
}

double Animation::GetOscillation(double restValue, double amplitude, double damping, double time)
{
	return restValue + amplitude * sin(time) * exp(time * damping);
}
