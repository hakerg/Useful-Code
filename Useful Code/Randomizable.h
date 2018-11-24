#pragma once
#include <stdlib.h>

class Randomizable
{
public:
	Randomizable();
	~Randomizable();

	virtual void Randomize() = 0;
	static double GetRandom();
	static double GetRandom(double min, double max);
	static int GetIntRandom(int min, int max);

	virtual void Mutate(double probability);

};

