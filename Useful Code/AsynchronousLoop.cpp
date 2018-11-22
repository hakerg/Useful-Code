#include "AsynchronousLoop.h"



void AsynchronousLoop::threadProc(AsynchronousLoop * object, void(*funcToLoop)(void *), void * funcParam, DWORD millisDelay)
{
	if (millisDelay)
	{

		while (object->running)
		{
			funcToLoop(funcParam);
			Sleep(millisDelay);
		}
	}
	else
	{
		while (object->running)
		{
			funcToLoop(funcParam);
		}
	}
}

AsynchronousLoop::AsynchronousLoop()
{
}


AsynchronousLoop::~AsynchronousLoop()
{
	if (running) Stop();
}

void AsynchronousLoop::Start(void(*funcToLoop)(void *), void * funcParam, DWORD millisDelay)
{
	running = true;
	thread = std::thread(threadProc, this, funcToLoop, funcParam, millisDelay);
}

void AsynchronousLoop::Stop()
{
	running = false;
	thread.join();
}

bool AsynchronousLoop::IsRunning()
{
	return running;
}
