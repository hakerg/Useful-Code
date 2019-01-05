#pragma once
#include "AnimationExponential.h"
#include "TimeDependent.h"

namespace uc
{

	// makes an animation by modifying continuously given external value
	class Oscilation :
		public TimeDependent
	{
	public:

		static const double QUARTER_SINE_ANGLE;

		double nominal, amplitude, speed_rad_per_second;
		double & value;
		std::chrono::duration<double> current_time;
		AnimationExponential amplitude_changer;

		Oscilation(
			double & value_,
			double nominal_,
			double init_amplitude_,
			std::chrono::duration<double> quarter_sine_time_,
			double damping_factor,
			double init_angle_ = 0.0);
		virtual ~Oscilation();

		// Odziedziczono za poœrednictwem elementu TimeDependent
		bool add_time(std::chrono::duration<double> delta_time) override;
	};

}