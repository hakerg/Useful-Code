#pragma once
#include <thread>
#include <Windows.h>
#include <time.h>

class LoopedThread
{

	std::thread thread;

public:

	bool Running;

	// funcToLoop: return false if thread has to be killed. Should not be looped
	template <class... FunctionArguments>
	LoopedThread(double loopPeriod_ms, bool(*functionToLoop)(FunctionArguments...), FunctionArguments&&... arguments)
	{
		Running = true;
		thread = std::thread(LoopFunctionPeriodically<FunctionArguments...>, &Running, loopPeriod_ms, functionToLoop, arguments...);
	}

	// funcToLoop: return false if thread has to be killed. Should not be looped
	template <class T, class... FunctionArguments>
	LoopedThread(double loopPeriod_ms, T* object, bool(T::*methodToLoop)(FunctionArguments...), FunctionArguments&&... arguments)
	{
		Running = true;
		thread = std::thread(LoopMethodPeriodically<T, FunctionArguments...>, &Running, loopPeriod_ms, object, methodToLoop, arguments...);
	}
	virtual ~LoopedThread();

	void RequestStop();
	void Stop();

	void WaitUntilFinished();


	// funcToLoop: return false to stop. Should not be looped; running: set to false to stop
	template <class... FunctionArguments>
	static void LoopFunctionPeriodically(bool * runningInput, double loopPeriod_ms, bool(*functionToLoop)(FunctionArguments...), FunctionArguments&&... arguments)
	{

		double nextTime = clock();

		while (*runningInput)
		{

			if (clock() < nextTime)
			{

				Sleep(1);
				continue;

			}

			if (!functionToLoop(arguments...))
			{
				*runningInput = false;
				return;
			}

			nextTime += loopPeriod_ms;

		}
	}

	// funcToLoop: return false to stop. Should not be looped; running: set to false to stop
	template <class T, class... FunctionArguments>
	static void LoopMethodPeriodically(bool * runningInput, double loopPeriod_ms, T* object, bool(T::*methodToLoop)(FunctionArguments...), FunctionArguments&&... arguments)
	{

		double nextTime = clock();

		while (*runningInput)
		{

			if (clock() < nextTime)
			{

				Sleep(1);
				continue;

			}

			if (!(object->*methodToLoop)(arguments...))
			{
				*runningInput = false;
				return;
			}

			nextTime += loopPeriod_ms;

		}
	}

};

