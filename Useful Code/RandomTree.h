#pragma once
#include "DataTransformer.h"
#include "Applicator.h"
#include <vector>
#include <utility>

template <class AIInputType, class AITurnType> class RandomTree :
	public DataTransformer<AIInputType, AITurnType>
{
public:

	unsigned MaxSteps;
	Applicator<AIInputType, AITurnType> * Simulator;


	RandomTree(unsigned maxSteps, Applicator<AIInputType, AITurnType> * simulator) :
		MaxSteps(maxSteps), Simulator(simulator) {}
	virtual ~RandomTree() {}


	virtual std::vector<AITurnType> GetTurnsToCheck(const AIInputType & input) const = 0;


	AIInputType GetFinalInput(const AIInputType & initInput, unsigned steps) const
	{

		steps--;

		auto turns = GetTurnsToCheck(initInput);
		unsigned turnsCount = turns.size();

		auto finalInput = Simulator->GetApplied(initInput, turns.front());

		if (steps > 0U)
		{

			finalInput = GetFinalInput(finalInput, steps);
			for (unsigned n = 1; n < turnsCount; n++)
			{
				auto tempFinalInput = Simulator->GetApplied(initInput, turns[n]);
				tempFinalInput = GetFinalInput(tempFinalInput, steps);

				if (finalInput < tempFinalInput) finalInput = tempFinalInput; // define operator < to determine, which one has higher fitness
			}

		}
		else
		{

			for (unsigned n = 1; n < turnsCount; n++)
			{
				auto tempFinalInput = Simulator->GetApplied(initInput, turns[n]);

				if (finalInput < tempFinalInput) finalInput = tempFinalInput; // define operator < to determine, which one has higher fitness
			}

		}

		return finalInput;
	}


	// Odziedziczono za poœrednictwem elementu AI
	virtual AITurnType GetOutput(const AIInputType & input) const override
	{
		
		unsigned steps = MaxSteps - 1;

		auto turns = GetTurnsToCheck(input);
		unsigned turnsCount = turns.size();

		auto& turn = turns[0];
		auto finalInput = Simulator->GetApplied(input, turn);
		if (steps > 0U)
		{

			finalInput = GetFinalInput(finalInput, steps);

			for (unsigned n = 1; n < turnsCount; n++)
			{
				auto& tempTurn = turns[n];
				auto tempFinalInput = Simulator->GetApplied(input, tempTurn);
				tempFinalInput = GetFinalInput(tempFinalInput, steps);

				if (finalInput < tempFinalInput) // define operator < to determine, which one has higher fitness
				{
					finalInput = tempFinalInput;
					turn = tempTurn;
				}
			}

		}
		else
		{

			for (unsigned n = 1; n < turnsCount; n++)
			{
				auto& tempTurn = turns[n];
				auto tempFinalInput = Simulator->GetApplied(input, tempTurn);

				if (finalInput < tempFinalInput) // define operator < to determine, which one has higher fitness
				{
					finalInput = tempFinalInput;
					turn = tempTurn;
				}
			}

		}

		return turn;
	}
};
