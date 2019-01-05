#pragma once
#include "Neuron.h"

namespace uc
{

	class NeuronSigmoid :
		public Neuron
	{
	public:
		NeuronSigmoid();
		virtual ~NeuronSigmoid();


		double activation_function(double input) const override;
		double derivative_function(double input) const override;
	};

}