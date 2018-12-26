#pragma once
#include "TimeDependent.h"

class AnimationExponential : public TimeDependent
{
public:

	double factor, target_value;
	double & value;

	AnimationExponential(double & _value, double _factor, double _target_value);
	virtual ~AnimationExponential();

	// Odziedziczono za poœrednictwem elementu TimeDependent
	virtual bool add_time(std::chrono::duration<double> delta_time) override;
};

