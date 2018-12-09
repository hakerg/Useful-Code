#include "LoopedThreadGroup.h"



LoopedThreadGroup::LoopedThreadGroup()
{
}


LoopedThreadGroup::~LoopedThreadGroup()
{
	StopAll();
}

void LoopedThreadGroup::RequestStopAll()
{
	for (auto& c : *this) c.RequestStop();
}

void LoopedThreadGroup::StopAll()
{
	RequestStopAll();
	WaitUntilAllFinished();
}

unsigned LoopedThreadGroup::RunningCount() const
{
	unsigned count = 0;
	for (auto& c : *this) if (c.Running) count++;
	return count;
}

void LoopedThreadGroup::WaitUntilAllFinished()
{
	for (auto& c : *this) c.WaitUntilFinished();
}
