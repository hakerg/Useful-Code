#include "LoopedThread.h"



LoopedThread::~LoopedThread()
{
	Stop();
}

void LoopedThread::RequestStop()
{
	Running = false;
}

void LoopedThread::Stop()
{
	RequestStop();
	WaitUntilFinished();
}


void LoopedThread::WaitUntilFinished()
{
	if (thread.joinable()) thread.join();
}
