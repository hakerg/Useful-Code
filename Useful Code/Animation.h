#pragma once
#include <math.h>
#include "Math defines.h"

class Animation
{
public:
	Animation();
	virtual ~Animation();

	virtual bool SetNextFrame() = 0; // true if success, false if animation finished


	template<class T> static void SetNextLinear(T * variable, T targetValue, T step);
	template<class T> static void SetNextExponential(T * variable, T targetValue, T factor);
	static double GetQuarterSine(double startValue, double targetOffset, double time); // time <0, 1>
	static double GetHalfCosine(double startValue, double targetOffset, double time); // time <0, 1>
	static double GetOscillation(double restValue, double amplitude, double damping, double time); // damping <0, oo)
};


template<class T>
inline void Animation::SetNextLinear(T * variable, T targetValue, T step)
{
	if (abs(*variable - targetValue) < step) *variable = targetValue;
	else if (*variable < targetValue) *variable += step;
	else *variable -= step;
}

template<class T>
inline void Animation::SetNextExponential(T * variable, T targetValue, T factor)
{
	*variable += (targetValue - *variable) * factor;
}

