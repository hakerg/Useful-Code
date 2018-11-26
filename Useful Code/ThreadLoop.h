#pragma once
#include <thread>
#include <Windows.h>
#include <time.h>
#include <utility>

class ThreadLoop
{

	std::thread thread;

	bool running = true;

public:

	template <class... FuncParams>
	ThreadLoop(double loopPeriod_ms, bool(*funcToLoop)(FuncParams...), FuncParams... funcParams) // return false if thread should be killed. func should not be looped
	{
		thread = std::thread(ThreadProc<FuncParams...>, &running, loopPeriod_ms, funcToLoop, funcParams...);
	}

	virtual ~ThreadLoop();

	void Stop();
	bool Running();

	template <class... FuncParams>
	static void ThreadProc(bool * running, double loopPeriod_ms, bool(*funcToLoop)(FuncParams...), FuncParams... funcParams)
	{

		double nextTime = clock();

		while (*running)
		{

			if (clock() < nextTime)
			{

				Sleep(1);
				continue;

			}

			if (!funcToLoop(funcParams...)) *running = false;

			nextTime += loopPeriod_ms;

		}

	}
};

