#pragma once
#include "DataTransformer.h"
#include "Randomizable.h"
#include "GraphOneWayConnection.h"

template <class NumType = double> class AISynapse :
	public DataTransformer<NumType, NumType>,
	public Randomizable,
	public GraphOneWayConnection
{
public:

	NumType Weight;


	AISynapse(NumType weight, void * target) : Weight(weight), GraphOneWayConnection(target) {}
	~AISynapse() {}

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

