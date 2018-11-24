#pragma once
#include <cmath>
#include "DataTransformer.h"
#include "Randomizable.h"
#include "GraphNode.h"

template <class NumType = double> class Neuron :
	public DataTransformer<NumType, NumType>,
	public Randomizable,
	public GraphNode
{
public:

	NumType OutputBias = 0;

	NumType(*ActivationFunction)(NumType) = Sigmoid;
	NumType(*DerivativeFunction)(NumType) = DerivativeSigmoid;



	Neuron() {}
	Neuron(NumType(*activationFunction)(NumType), NumType(*derivativeFunction)(NumType))
		: ActivationFunction(activationFunction), DerivativeFunction(derivativeFunction) {}
	~Neuron() {}


	static NumType Sigmoid(NumType input) // (-oo, oo) -> (0, 1)
	{


		return 1.0 / (1.0 + exp(-input));
	}

	
	static NumType DerivativeSigmoid(NumType input)
	{

		NumType s = Sigmoid(input);
		return s * (1.0 - s);

	}

	// Odziedziczono za poœrednictwem elementu Randomizable
	virtual void Randomize() override
	{
		OutputBias = GetRandom(-1.0, 1.0);
	}

	// Odziedziczono za poœrednictwem elementu DataTransformer
	virtual NumType GetOutput(const NumType & input) override
	{
		return ActivationFunction(input) + OutputBias;
	}
};

