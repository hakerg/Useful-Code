#include "Synapse.h"
#include "Neuron.h"


std::default_random_engine Synapse::_generator;
std::normal_distribution<double> Synapse::_normal_distribution;


Synapse::Synapse(Node * _source, Node * _target) : Connection(_source, _target) {}

Synapse::~Synapse() {}

double Synapse::output() const
{
	return source<Neuron>()->output() * weight + bias;
}

void Synapse::add_delta(double deltaOutput)
{
	_delta_bias += deltaOutput;
	_delta_weight += deltaOutput * source<Neuron>()->output();
	source<Neuron>()->add_delta(deltaOutput * weight);
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
