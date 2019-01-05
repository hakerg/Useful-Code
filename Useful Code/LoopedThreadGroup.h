#pragma once
#include <vector>
#include "LoopedThread.h"

namespace uc
{

	// controls group of LoopedThread objects
	class LoopedThreadGroup :
		public std::vector<LoopedThread>
	{
	public:
		LoopedThreadGroup();
		virtual ~LoopedThreadGroup();

		void request_stop_all();
		void stop_all();
		unsigned running_count() const;

		void wait_until_all_finished();

	};

}