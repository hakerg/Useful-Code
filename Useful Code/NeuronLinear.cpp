#include "NeuronLinear.h"

namespace uc
{

	NeuronLinear::NeuronLinear()
	{
	}


	NeuronLinear::~NeuronLinear()
	{
	}

	double NeuronLinear::activation_function(double input) const
	{
		return input;
	}

	double NeuronLinear::derivative_function(double input) const
	{
		return 1.0;
	}

}