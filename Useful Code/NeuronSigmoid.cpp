#include "NeuronSigmoid.h"

namespace uc
{

	NeuronSigmoid::NeuronSigmoid()
	{
	}


	NeuronSigmoid::~NeuronSigmoid()
	{
	}


	double NeuronSigmoid::activation_function(double input) const
	{
		return 1.0 / (1.0 + exp(-input));
	}

	double NeuronSigmoid::derivative_function(double input) const
	{
		double s = activation_function(input);
		return s * (1.0 - s);
	}

}