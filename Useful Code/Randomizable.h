#pragma once

namespace uc
{

	class Randomizable
	{
	public:
		Randomizable();
		virtual ~Randomizable();

		// sets all data members to random values
		virtual void randomize() = 0;

		// randomizes object with a certain probability
		// you can override this method with a mutation algorithm
		virtual void mutate(double probability);

	};

}