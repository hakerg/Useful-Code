#include "Randomizable.h"
#include <stdlib.h>



Randomizable::Randomizable()
{
}


Randomizable::~Randomizable()
{
}

void Randomizable::mutate(double probability)
{
	if (rand() < probability * (RAND_MAX + 1)) randomize();
}
