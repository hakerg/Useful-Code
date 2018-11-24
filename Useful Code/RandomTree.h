#pragma once
#include "DataTransformer.h"
#include "Applicator.h"
#include <vector>
#include <utility>

template <class AIInputType, class AITurnType> class RandomTree :
	public DataTransformer<AIInputType, AITurnType>
{
public:

	int MaxSteps;
	Applicator<AIInputType, AITurnType> * Simulator;


	RandomTree(int maxSteps, Applicator<AIInputType, AITurnType> * simulator) :
		MaxSteps(maxSteps), Simulator(simulator) {}
	~RandomTree() {}


	virtual std::vector<AITurnType> GetTurnsToCheck(const AIInputType & input) = 0;


	AIInputType GetFinalInput(const AIInputType & initInput, int steps)
	{

		steps--;

		auto turns = GetTurnsToCheck(initInput);
		int turnsCount = turns.size();

		auto finalInput = Simulator->GetApplied(initInput, turns[0]);
		if (steps > 0) finalInput = GetFinalInput(finalInput, steps);

		for (int n = 1; n < turnsCount; n++)
		{
			auto tempFinalInput = Simulator->GetApplied(initInput, turns[n]);
			if (steps > 0) tempFinalInput = GetFinalInput(tempFinalInput, steps);

			if (finalInput < tempFinalInput) finalInput = tempFinalInput; // define operator < to determine, which one has higher fitness
		}

		return finalInput;
	}


	// Odziedziczono za poœrednictwem elementu AI
	virtual AITurnType GetOutput(const AIInputType & input) override
	{

		int steps = MaxSteps - 1;

		auto turns = GetTurnsToCheck(input);
		int turnsCount = turns.size();

		auto& turn = turns[0];
		auto finalInput = Simulator->GetApplied(input, turn);
		if (steps > 0) finalInput = GetFinalInput(finalInput, steps);

		for (int n = 1; n < turnsCount; n++)
		{
			auto& tempTurn = turns[n];
			auto tempFinalInput = Simulator->GetApplied(input, tempTurn);
			if (steps > 0) tempFinalInput = GetFinalInput(tempFinalInput, steps);

			if (finalInput < tempFinalInput) // define operator < to determine, which one has higher fitness
			{
				finalInput = tempFinalInput;
				turn = tempTurn;
			}
		}

		return turn;
	}
};
