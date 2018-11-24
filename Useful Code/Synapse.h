#pragma once
#include "DataTransformer.h"
#include "Randomizable.h"
#include "GraphOneWayConnection.h"

template <class NumType = double> class Synapse :
	public DataTransformer<NumType, NumType>,
	public Randomizable,
	public GraphOneWayConnection
{
public:

	NumType Weight;


	Synapse(NumType weight, void * target) : Weight(weight), GraphOneWayConnection(target) {}
	~Synapse() {}

	// Odziedziczono za poœrednictwem elementu DataTransformer
	virtual NumType GetOutput(const NumType & input) override
	{
		return input * Weight;
	}

	// Odziedziczono za poœrednictwem elementu Randomizable
	virtual void Randomize() override
	{
		Weight = GetRandom(-1.0, 1.0);
	}
};

