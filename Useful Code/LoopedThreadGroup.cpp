#include "LoopedThreadGroup.h"

namespace uc
{

	LoopedThreadGroup::LoopedThreadGroup()
	{
	}


	LoopedThreadGroup::~LoopedThreadGroup()
	{
		stop_all();
	}

	void LoopedThreadGroup::request_stop_all()
	{
		for (auto& c : *this) c.request_stop();
	}

	void LoopedThreadGroup::stop_all()
	{
		request_stop_all();
		wait_until_all_finished();
	}

	unsigned LoopedThreadGroup::running_count() const
	{
		unsigned count = 0;
		for (auto& c : *this) if (c.running) count++;
		return count;
	}

	void LoopedThreadGroup::wait_until_all_finished()
	{
		for (auto& c : *this) c.wait_until_finished();
	}

}