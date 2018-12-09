#pragma once
#include "LoopedThread.h"
#include <vector>

class LoopedThreadGroup :
	public std::vector<LoopedThread>
{
public:
	LoopedThreadGroup();
	virtual ~LoopedThreadGroup();

	void RequestStopAll();
	void StopAll();
	unsigned RunningCount() const;

	void WaitUntilAllFinished();

};

