#pragma once
#include <chrono>
#include <thread>

class LoopedThread
{

	std::thread _thread;

public:

	bool running;
	std::chrono::nanoseconds period;

	// funcToLoop: return false if thread has to be killed. Should not be looped
	template <class... _Args>
	LoopedThread(std::chrono::duration<double> _period, bool _wait_until_first_execution, bool(*_function_to_loop)(_Args...), _Args&&... _args)
		: period(std::chrono::duration_cast<std::chrono::nanoseconds>(_period)), running(true)
	{
		_thread = std::thread(&LoopedThread::loop_function_periodically<_Args...>, this, _wait_until_first_execution, _function_to_loop, _args...);
	}

	// funcToLoop: return false if thread has to be killed. Should not be looped
	template <class _Class, class... _Args>
	LoopedThread(std::chrono::duration<double> _period, bool _wait_until_first_execution, _Class* _object, bool(_Class::*_method_to_loop)(_Args...), _Args&&... _args)
		: period(std::chrono::duration_cast<std::chrono::nanoseconds>(_period)), running(true)
	{
		_thread = std::thread(&LoopedThread::loop_method_periodically<_Class, _Args...>, this, _wait_until_first_execution, _object, _method_to_loop, _args...);
	}

	virtual ~LoopedThread();

	void request_stop();
	void stop();

	void wait_until_finished();


	// funcToLoop: return false to stop. Should not be looped; running: set to false to stop
	template <class... _Args>
	void loop_function_periodically(bool wait_until_first_execution, bool(*function_to_loop)(_Args...), _Args&&... args)
	{

		std::chrono::high_resolution_clock::time_point next_call_time = std::chrono::high_resolution_clock::now();

		if (wait_until_first_execution) next_call_time += period;

		while (running)
		{

			if (std::chrono::high_resolution_clock::now() < next_call_time)
			{

				std::this_thread::yield();
				continue;

			}

			if (!function_to_loop(args...))
			{
				running = false;
				return;
			}

			next_call_time += period;

		}
	}

	// funcToLoop: return false to stop. Should not be looped; running: set to false to stop
	template <class _Class, class... _Args>
	void loop_method_periodically(bool wait_until_first_execution, _Class* object, bool(_Class::*method_to_loop)(_Args...), _Args&&... args)
	{

		std::chrono::high_resolution_clock::time_point next_call_time = std::chrono::high_resolution_clock::now();

		if (wait_until_first_execution) next_call_time += period;

		while (running)
		{

			if (std::chrono::high_resolution_clock::now() < next_call_time)
			{

				std::this_thread::yield();
				continue;

			}

			if (!(object->*method_to_loop)(args...))
			{
				running = false;
				return;
			}

			next_call_time += period;

		}
	}

};

