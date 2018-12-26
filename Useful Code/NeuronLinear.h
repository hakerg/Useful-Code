#pragma once
#include "Neuron.h"
class NeuronLinear :
	public Neuron
{
public:
	NeuronLinear();
	virtual ~NeuronLinear();

	virtual double activation_function(double input) const override;
	virtual double derivative_function(double input) const override;
};

