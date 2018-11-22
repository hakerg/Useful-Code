#pragma once
#include "DataTransformer.h"
#include <vector>
#include <utility>

template <class AIInputType, class AIOutputType> class AIRandomTree :
	public DataTransformer<AIInputType, AIOutputType>
{
public:

	int MaxSteps;
	DataTransformer<std::pair<AIInputType, AIOutputType>, AIOutputType> * SimulationProvider;


	AIRandomTree(int maxSteps, DataTransformer<std::pair<AIInputType, AIOutputType>, AIOutputType> * simulationProvider) :
		MaxSteps(maxSteps), SimulationProvider(simulationProvider) {}
	~AIRandomTree() {}


	virtual std::vector<AIOutputType> GetOutputsToCheck(const AIInputType & input) = 0;

	virtual bool IsBetterThan(const AIInputType & lhs, const AIInputType & rhs) = 0; // return lhs fitness > rhs fitness


	AIInputType GetFinalInput(const AIInputType & initInput, int steps)
	{

		steps--;

		auto outputs = GetOutputsToCheck(initInput);
		int outputsCount = outputs.size();

		auto finalInput = SimulationProvider->GetOutput(std::pair<AIInputType, AIOutputType>(initInput, outputs[0]));
		if (steps > 0) finalInput = GetFinalInput(finalInput, steps);

		for (int n = 1; n < outputsCount; n++)
		{
			auto tempFinalInput = SimulationProvider->GetOutput(std::pair<AIInputType, AIOutputType>(initInput, outputs[n]));
			if (steps > 0) tempFinalInput = GetFinalInput(tempFinalInput, steps);

			if (IsBetterThan(tempFinalInput, finalInput)) finalInput = tempFinalInput;
		}

		return finalInput;
	}


	// Odziedziczono za poœrednictwem elementu AI
	virtual AIOutputType GetOutput(const AIInputType & input) override
	{

		int steps = MaxSteps - 1;

		auto outputs = GetOutputsToCheck(input);
		int outputsCount = outputs.size();

		auto& output = outputs[0];
		auto finalInput = SimulationProvider->GetOutput(std::pair<AIInputType, AIOutputType>(input, output));
		if (steps > 0) finalInput = GetFinalInput(finalInput, steps);

		for (int n = 1; n < outputsCount; n++)
		{
			auto& tempOutput = outputs[n];
			auto tempFinalInput = SimulationProvider->GetOutput(std::pair<AIInputType, AIOutputType>(input, tempOutput));
			if (steps > 0) tempFinalInput = GetFinalInput(tempFinalInput, steps);

			if (IsBetterThan(tempFinalInput, finalInput))
			{
				finalInput = tempFinalInput;
				output = tempOutput;
			}
		}

		return output;
	}
};
