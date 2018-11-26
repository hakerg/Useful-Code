#include <iostream>
#include <Windows.h>
#include "RealtimeAnimation.h"

class TestAnimation : public Animatable
{
	int id = 0;

	// Odziedziczono za poœrednictwem elementu Animatable
	virtual void Draw() const override
	{
		std::cout << "Frame #" << id << std::endl;
	}
	virtual std::shared_ptr<Animatable> GetNextFrame() const override
	{
		if (id == 10) return GetNullFrame();

		std::shared_ptr<TestAnimation> nextFrame(new TestAnimation(*this));
		nextFrame->id++;
		return nextFrame;
	}
};


int main()
{
	RealtimeAnimation runner;

	std::shared_ptr<Animatable> animation(new TestAnimation());
	runner.Run(animation, 100);
	runner.Run(animation, 1000);


	std::cout << std::endl;
	system("pause");
	return 0;
}