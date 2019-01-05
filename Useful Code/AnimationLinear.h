#pragma once
#include "TimeLimited.h"

namespace uc
{

	// makes an animation by modifying continuously given external value
	class AnimationLinear :
		public TimeLimited
	{

		bool _add_time(std::chrono::duration<double> delta_time) override;

	public:

		double change_speed_per_second;
		double & value;

		template <class _Rep, class _Period>
		AnimationLinear(double & value_, double change_speed_per_second_, std::chrono::duration<_Rep, _Period> time_) :
			value(value_), change_speed_per_second(change_speed_per_second_), TimeLimited(std::chrono::duration_cast<std::chrono::duration<double>>(time_)) {}
		virtual ~AnimationLinear();
	};

}