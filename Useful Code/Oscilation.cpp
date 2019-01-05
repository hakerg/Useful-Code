#include "Oscilation.h"
#include "math_defines.h"

namespace uc
{

	const double Oscilation::QUARTER_SINE_ANGLE = PI_2;


	Oscilation::Oscilation(
		double & value_,
		double nominal_,
		double init_amplitude_,
		std::chrono::duration<double> quarter_sine_time_,
		double damping_factor,
		double init_angle_)
		:
		value(value_),
		nominal(nominal_),
		amplitude(init_amplitude_),
		speed_rad_per_second(QUARTER_SINE_ANGLE / quarter_sine_time_.count()),
		amplitude_changer(amplitude, damping_factor, 0.0),
		current_time(init_angle_ * quarter_sine_time_.count() / QUARTER_SINE_ANGLE)
	{
	}


	Oscilation::~Oscilation()
	{
	}

	bool Oscilation::add_time(std::chrono::duration<double> delta_time)
	{
		current_time += delta_time;
		amplitude_changer.add_time(delta_time);
		value = nominal + amplitude * sin(current_time.count() * speed_rad_per_second);

		return true;
	}

}