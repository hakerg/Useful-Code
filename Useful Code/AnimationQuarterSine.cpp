#include "AnimationQuarterSine.h"

namespace uc
{

	AnimationQuarterSine::~AnimationQuarterSine()
	{
	}

	bool AnimationQuarterSine::_add_time(std::chrono::duration<double> delta_time)
	{
		value = nominal + target_offset * cos(time_left.count() * speed_rad_per_second);

		return true;

	}

}