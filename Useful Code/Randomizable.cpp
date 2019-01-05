#include "Randomizable.h"
#include <stdlib.h>

namespace uc
{

	Randomizable::Randomizable()
	{
	}


	Randomizable::~Randomizable()
	{
	}

	void Randomizable::mutate(double probability)
	{
		if (rand() < probability * (RAND_MAX + 1.0)) randomize();
	}

}