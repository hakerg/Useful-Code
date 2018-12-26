#pragma once
#include "DirectedGraph.h"
#include <vector>
#include "AI.h"
#include "Neuron.h"
#include "Randomizable.h"
#include "Synapse.h"


class NeuralNetwork :
	public AI<double*, std::vector<double>>,
	public DirectedGraph,
	public Randomizable
{
public:

	DirectedGraph input_layer, output_layer;


	NeuralNetwork();
	NeuralNetwork(unsigned _input_count, unsigned _output_count);
	NeuralNetwork(unsigned _input_count, unsigned _output_count, const std::vector<unsigned>& _hidden_layers_size);
	virtual ~NeuralNetwork();

	void add_inputs(unsigned count);
	void add_outputs(unsigned count);

	void set_input(double * input_data);
	void output(double * output_data);
	void connect_layers(DirectedGraph::iterator source_begin, DirectedGraph::iterator source_end, DirectedGraph::iterator target_begin, DirectedGraph::iterator target_end);

	void add_delta(double * expected_output, double factor);
	void apply_delta();

	// Odziedziczono za poœrednictwem elementu Randomizable
	virtual void randomize() override;
	virtual void mutate(double probability) override;

	// Odziedziczono za poœrednictwem elementu AI
	virtual std::vector<double> best_turn(double* const & state) override;
};

