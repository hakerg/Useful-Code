#include "Synapse.h"
#include "Neuron.h"

namespace uc
{

	std::default_random_engine Synapse::_generator;
	std::normal_distribution<double> Synapse::_normal_distribution;


	Synapse::Synapse(Node * source_, Node * target_) : Connection(source_, target_) {}

	Synapse::~Synapse() {}

	double Synapse::output() const
	{
		return source<Neuron>()->output() * weight + bias;
	}

	void Synapse::add_delta(double delta_output)
	{
		_delta_bias += delta_output;
		_delta_weight += delta_output * source<Neuron>()->output();
		source<Neuron>()->add_delta(delta_output * weight);
	}

	void Synapse::apply_delta()
	{
		weight += _delta_weight; _delta_weight = 0.0;
		bias += _delta_bias; _delta_bias = 0.0;
	}

	// Odziedziczono za poœrednictwem elementu Randomizable

	void Synapse::randomize()
	{
		weight = _normal_distribution(_generator);
		bias = _normal_distribution(_generator);
	}

}