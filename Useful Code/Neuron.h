#pragma once
#include <cmath>
#include "Node.h"

class Neuron :
	public Node
{
	double _output = nan("");
	double _derivative_output = nan("");

	void _invalidate_outcoming_connections();

public:

	Neuron();
	virtual ~Neuron();

	virtual double activation_function(double input) const = 0;
	virtual double derivative_function(double input) const = 0;

	const double& output();
	void set_input(double input);


	void add_delta(double delta_output);

};