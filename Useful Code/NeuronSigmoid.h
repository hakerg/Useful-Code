#pragma once
#include "Neuron.h"
class NeuronSigmoid :
	public Neuron
{
public:
	NeuronSigmoid();
	virtual ~NeuronSigmoid();


	virtual double activation_function(double input) const override;
	virtual double derivative_function(double input) const override;
};

