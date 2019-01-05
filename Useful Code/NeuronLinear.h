#pragma once
#include "Neuron.h"

namespace uc
{

	class NeuronLinear :
		public Neuron
	{
	public:
		NeuronLinear();
		virtual ~NeuronLinear();

		double activation_function(double input) const override;
		double derivative_function(double input) const override;
	};

}