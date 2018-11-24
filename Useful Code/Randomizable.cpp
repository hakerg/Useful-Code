#include "Randomizable.h"



Randomizable::Randomizable()
{
}


Randomizable::~Randomizable()
{
}

double Randomizable::GetRandom()
{
	return rand() / (RAND_MAX + 1.0);
}

double Randomizable::GetRandom(double min, double max)
{
	return rand() * (max - min) / RAND_MAX + min;
}

int Randomizable::GetIntRandom(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

void Randomizable::Mutate(double probability)
{
	if (GetRandom() < probability) Randomize();
}
