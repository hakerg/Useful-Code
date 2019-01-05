#pragma once
#include "DirectedGraph.h"
#include <vector>
#include "AI.h"
#include "Neuron.h"
#include "Randomizable.h"
#include "Synapse.h"

namespace uc
{

	// use input_layer and output_layer to store input and output neurons respectively
	// notice that input/output values are affected by the activation function
	// to avoid this, use NeuronLinear as layers' elements
	class NeuralNetwork :
		public AI<double*, std::vector<double>>,
		public DirectedGraph,
		public Randomizable
	{
	public:

		DirectedGraph input_layer, output_layer;


		NeuralNetwork();

		// fills input_layer and output_layer with NeuronLinear objects but makes no connetions
		NeuralNetwork(unsigned input_count_, unsigned output_count_);

		// fills input_layer and output_layer with NeuronLinear objects
		// adds hidden layers of neurons with sigmoid as their activation function
		// connects layers with random synapses
		NeuralNetwork(unsigned input_count_, unsigned output_count_, const std::vector<unsigned>& hidden_layers_size_);
		virtual ~NeuralNetwork();

		// increases the number of inputs
		// makes no connections
		void add_inputs(unsigned count);

		// increases the number of outputs
		// makes no connections
		void add_outputs(unsigned count);

		// copy input_data to inputs of the input layer
		void set_input(double * input_data);

		// copy outputs of the output layer to output_data
		void output(double * output_data);

		// connects layers with random synapses
		static void connect_layers(DirectedGraph::iterator source_begin, DirectedGraph::iterator source_end, DirectedGraph::iterator target_begin, DirectedGraph::iterator target_end);

		// give network learning data
		// factor - higher values makes network learn faster, but more inaccurate
		// call apply_delta() to adjust the network
		void add_delta(double * expected_output, double factor);

		// modifies network to fit given training data
		void apply_delta();

		// randomizes all connections in network using normal distribution as probability distribution
		void randomize() override;

		// randomizes only some connections
		virtual void mutate(double probability) override;

		// set input to the network and receive output
		std::vector<double> best_turn(double* const & state) override;
	};

}