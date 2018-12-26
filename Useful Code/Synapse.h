#pragma once
#include <random>
#include "Connection.h"
#include "Randomizable.h"

class Synapse :
	public Connection,
	public Randomizable
{

	static std::default_random_engine _generator;
	static std::normal_distribution<double> _normal_distribution;
	double _delta_weight = 0.0;
	double _delta_bias = 0.0;

public:

	double weight = _normal_distribution(_generator);
	double bias = _normal_distribution(_generator);


	Synapse(Node * _source, Node * _target);
	virtual ~Synapse();

	double output() const;

	void add_delta(double deltaOutput);
	void apply_delta();

	// Odziedziczono za poœrednictwem elementu Randomizable
	virtual void randomize() override;
};