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

	// Odziedziczono za po�rednictwem elementu DataTransformer
	virtual NumType GetOutput(const NumType & input) override
	{
		return input * Weight;
	}

	// Odziedziczono za po�rednictwem elementu Randomizable
	virtual void Randomize() override
	{
		Weight = GetRandom(-1.0, 1.0);
	}
};

