#pragma once
#include "math_defines.h"
#include "TimeLimited.h"

namespace uc
{

	// makes an animation by modifying continuously given external value
	class AnimationQuarterSine :
		public TimeLimited
	{

		bool _add_time(std::chrono::duration<double> delta_time) override;

	public:

		double nominal, target_offset, speed_rad_per_second;
		double & value;

		template <class _Rep, class _Period>
		AnimationQuarterSine(double & value_, double target_offset_, std::chrono::duration<_Rep, _Period> time_) :
			value(value_),
			nominal(value_),
			target_offset(target_offset_),
			speed_rad_per_second(PI_2 / std::chrono::duration_cast<std::chrono::duration<double>>(time_).count()),
			TimeLimited(std::chrono::duration_cast<std::chrono::duration<double>>(time_)) {}

		virtual ~AnimationQuarterSine();
	};

}