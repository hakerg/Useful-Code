#include "AnimationSine.h"



const double AnimationSine::HALF_SINE_ANGLE = PI_2;


AnimationSine::AnimationSine(
	double & _value,
	double _nominal_value,
	double _amplitude,
	std::chrono::duration<double> _half_sine_time,
	std::chrono::duration<double> _total_time,
	double _init_angle) :

	value(_value),
	nominal_value(_nominal_value),
	amplitude(_amplitude),
	speed_rad_per_second(HALF_SINE_ANGLE / _half_sine_time.count()),
	remaining_time(_total_time),
	current_time(_init_angle * _half_sine_time / HALF_SINE_ANGLE)
{
}


AnimationSine::~AnimationSine()
{
}

bool AnimationSine::add_time(std::chrono::duration<double> delta_time)
{
	if (delta_time > remaining_time) delta_time = remaining_time;

	current_time += delta_time;
	remaining_time -= delta_time;

	value = nominal_value + amplitude * sin(current_time.count() * speed_rad_per_second);

	return remaining_time > std::chrono::duration<double>::zero();

}
