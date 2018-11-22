#include <iostream>
#include <Windows.h>
#include "AINeuralNetwork.h"

int main()
{
	AINeuralNetwork<3, 3> network(std::vector<int>({ 3 }), AINeuron<>());

	std::array<double, 3> input;
	for (auto& i : input) i = Randomizable::GetRandom(-1.0, 1.0);

	while (true)
	{

		network.Teach(input, input, 0.1);

		auto output = network.GetOutput(input);

		for (auto& o : output) std::cout << o << ", ";
		std::cout << std::endl;

	}


	std::cout << std::endl;
	system("pause");
	return 0;
}