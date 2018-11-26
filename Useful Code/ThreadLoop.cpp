#include "ThreadLoop.h"



ThreadLoop::~ThreadLoop()
{
	Stop();
}

void ThreadLoop::Stop()
{
	running = false;
	if (thread.joinable()) thread.join();
}

bool ThreadLoop::Running()
{
	return running;
}
