#include "AnimationLinear.h"



AnimationLinear::AnimationLinear(double & _value, double _change_speed_per_second, std::chrono::duration<double> _total_time)
	: value(_value), change_speed_per_second(_change_speed_per_second), remaining_time(_total_time)
{
}


AnimationLinear::~AnimationLinear()
{
}

bool AnimationLinear::add_time(std::chrono::duration<double> delta_time)
{
	if (delta_time > remaining_time) delta_time = remaining_time;

	remaining_time -= delta_time;
	value += delta_time.count() * change_speed_per_second;

	return remaining_time > std::chrono::duration<double>::zero();

}
