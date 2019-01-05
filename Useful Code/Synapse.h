#pragma once
#include <random>
#include "Connection.h"
#include "Randomizable.h"

namespace uc
{

	// synapse used by neural network
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


		Synapse(Node * source_, Node * target_);
		virtual ~Synapse();

		double output() const;

		// add gradient
		void add_delta(double delta_output);

		// apply gradient
		// this modifies weight and bias and learns this connection
		// call this on every synapse in the network after adding gradient
		void apply_delta();

		// randomizes weight and bias using random numbers with normal distribution
		void randomize() override;
	};

}