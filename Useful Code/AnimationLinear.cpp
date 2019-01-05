#include "AnimationLinear.h"

namespace uc
{

	AnimationLinear::~AnimationLinear()
	{
	}

	bool AnimationLinear::_add_time(std::chrono::duration<double> delta_time)
	{
		value += delta_time.count() * change_speed_per_second;

		return true;

	}

}