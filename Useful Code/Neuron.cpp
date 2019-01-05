#include "Neuron.h"
#include "Synapse.h"

namespace uc
{

	void Neuron::_invalidate_outcoming_connections()
	{
		for (auto& outcoming_synapse : outcoming_connections())
		{
			Neuron& target_neuron = *outcoming_synapse->target<Neuron>();
			if (!isnan(target_neuron._output))
			{
				target_neuron._output = nan("");
				target_neuron._invalidate_outcoming_connections();
			}
		}
	}

	Neuron::Neuron()
	{
	}

	Neuron::~Neuron() {}

	const double & Neuron::output()
	{
		if (isnan(_output))
		{
			double input = 0.0;
			for (auto& incoming_synapse : incoming_connections())
			{
				input += incoming_synapse->cast<Synapse>()->output();
			}
			set_input(input);
		}
		return _output;
	}

	void Neuron::set_input(double input)
	{
		double new_output = activation_function(input);
		if (new_output != _output)
		{
			_output = new_output;
			_invalidate_outcoming_connections();
		}
		_derivative_output = derivative_function(input);
	}

	void Neuron::add_delta(double delta_output)
	{
		for (auto& incoming_synapse : incoming_connections())
		{
			incoming_synapse->cast<Synapse>()->add_delta(delta_output * _derivative_output);
		}
	}

}