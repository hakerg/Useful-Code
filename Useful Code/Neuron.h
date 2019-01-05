#pragma once
#include <cmath>
#include "Node.h"

namespace uc
{

	// neuron class used by neural network
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

		// used by back-propagation algorithm
		// forces input neurons to give proper value
		void add_delta(double delta_output);

	};

}