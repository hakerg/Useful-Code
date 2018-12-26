#pragma once
#include "math_defines.h"
#include "TimeDependent.h"

class AnimationSine :
	public TimeDependent
{
public:

	static const double HALF_SINE_ANGLE;

	double nominal_value, amplitude, speed_rad_per_second;
	double & value;
	std::chrono::duration<double> remaining_time, current_time;

	AnimationSine(
		double & _value,
		double _nominal_value,
		double _amplitude,
		std::chrono::duration<double> _half_size_time,
		std::chrono::duration<double> _total_time,
		double _init_angle = 0.0);

	virtual ~AnimationSine();

	// Odziedziczono za poœrednictwem elementu ContinuousValueChanger
	virtual bool add_time(std::chrono::duration<double> delta_time) override;
};

