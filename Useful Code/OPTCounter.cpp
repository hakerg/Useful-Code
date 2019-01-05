#include "OPTCounter.h"

namespace uc
{

	OPTCounter::~OPTCounter()
	{
	}

	void OPTCounter::insert_time_point()
	{
		timing_queue.push(std::chrono::high_resolution_clock::now());
	}

	unsigned OPTCounter::counter()
	{
		auto min_time_point = std::chrono::high_resolution_clock::now() - period;

		while (timing_queue.size())
		{
			if (timing_queue.front() <= min_time_point) timing_queue.pop();
			else break;
		}

		return timing_queue.size();
	}

}