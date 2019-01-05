#include "NeuralNetwork.h"
#include "NeuronLinear.h"
#include "NeuronSigmoid.h"

namespace uc
{

	NeuralNetwork::NeuralNetwork()
	{
	}

	NeuralNetwork::NeuralNetwork(unsigned input_count_, unsigned output_count_)
	{
		add_inputs(input_count_);
		add_outputs(output_count_);
	}

	NeuralNetwork::NeuralNetwork(unsigned input_count_, unsigned output_count_, const std::vector<unsigned>& hidden_layer_sizes_)
	{

		add_inputs(input_count_);
		add_outputs(output_count_);

		DirectedGraph::iterator source_begin = input_layer.begin();
		DirectedGraph::iterator source_end = input_layer.end();
		DirectedGraph::iterator target_begin, target_end;

		bool check_source_end = false;

		for (auto layer_size : hidden_layer_sizes_)
		{

			target_begin = end();
			while (layer_size)
			{
				add_node<NeuronSigmoid>();
				if (target_begin == end()) target_begin--;
				if (check_source_end)
				{
					if (source_end == end()) source_end--;
				}
				layer_size--;
			}
			target_end = end();

			connect_layers(source_begin, source_end, target_begin, target_end);

			source_begin = target_begin;
			source_end = target_end;
			check_source_end = true;

		}

		target_begin = output_layer.begin();
		target_end = output_layer.end();

		connect_layers(source_begin, source_end, target_begin, target_end);

	}


	NeuralNetwork::~NeuralNetwork()
	{
	}

	void NeuralNetwork::add_inputs(unsigned count)
	{
		while (count)
		{
			input_layer.add_node<NeuronLinear>();
			count--;
		}
	}

	void NeuralNetwork::add_outputs(unsigned count)
	{
		while (count)
		{
			output_layer.add_node<NeuronLinear>();
			count--;
		}
	}

	void NeuralNetwork::set_input(double * input_data)
	{
		for (auto& input_node : input_layer)
		{
			input_node->cast<Neuron>()->set_input(*input_data);
			input_data++;
		}
	}

	void NeuralNetwork::output(double * output_data)
	{
		for (auto& output_node : output_layer)
		{
			*output_data = output_node->cast<Neuron>()->output();
			output_data++;
		}
	}

	void NeuralNetwork::connect_layers(DirectedGraph::iterator source_begin, DirectedGraph::iterator source_end, DirectedGraph::iterator target_begin, DirectedGraph::iterator target_end)
	{
		for (auto source = source_begin; source != source_end; source++)
		{
			for (auto target = target_begin; target != target_end; target++)
			{
				Node::connect<Synapse>(&**source, &**target);
			}
		}
	}

	void NeuralNetwork::add_delta(double * expected_output, double factor)
	{
		for (auto& output_node : output_layer)
		{
			Neuron* output_neuron = output_node->cast<Neuron>();
			output_neuron->add_delta((*expected_output - output_neuron->output()) * factor);
			expected_output++;
		}
	}

	void NeuralNetwork::apply_delta()
	{
		for (auto& node : input_layer)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->apply_delta();
			}
		}

		for (auto& node : *this)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->apply_delta();
			}
		}
	}

	void NeuralNetwork::randomize()
	{
		for (auto& node : input_layer)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->randomize();
			}
		}

		for (auto& node : *this)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->randomize();
			}
		}
	}

	void NeuralNetwork::mutate(double probability)
	{
		for (auto& node : input_layer)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->mutate(probability);
			}
		}

		for (auto& node : *this)
		{
			for (auto& connection : node->cast<Neuron>()->outcoming_connections())
			{
				connection->cast<Synapse>()->mutate(probability);
			}
		}
	}

	std::vector<double> NeuralNetwork::best_turn(double * const & state)
	{
		set_input(state);

		std::vector<double> ret(output_layer.size());
		output(&ret.front());
		return ret;

	}

}