#pragma once
#include "TimeDependent.h"
class AnimationLinear :
	public TimeDependent
{
public:

	double change_speed_per_second;
	double & value;
	std::chrono::duration<double> remaining_time;

	AnimationLinear(double & _value, double _change_speed_per_second, std::chrono::duration<double> _total_time);
	virtual ~AnimationLinear();

	// Odziedziczono za poœrednictwem elementu ContinuousValueChanger
	virtual bool add_time(std::chrono::duration<double> delta_time) override;
};

