#pragma once
#include <chrono>
#include <queue>

namespace uc
{

	// counts operations per given time period
	class OPTCounter
	{

		std::queue<std::chrono::high_resolution_clock::time_point> timing_queue;

	public:

		std::chrono::high_resolution_clock::duration period;

		template <class _Duration> OPTCounter(_Duration period_) :
			period(std::chrono::duration_cast<std::chrono::high_resolution_clock::duration>(period_)) {}
		virtual ~OPTCounter();

		// count an operation
		void insert_time_point();

		// get counter value
		unsigned counter();

	};

}