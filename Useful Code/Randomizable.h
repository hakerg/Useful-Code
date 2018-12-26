#pragma once

class Randomizable
{
public:
	Randomizable();
	virtual ~Randomizable();

	virtual void randomize() = 0;

	virtual void mutate(double probability);

};

