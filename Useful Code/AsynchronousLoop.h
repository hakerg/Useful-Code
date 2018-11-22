#pragma once
#include <thread>
#include <Windows.h>

class AsynchronousLoop
{

	std::thread thread;

	bool running = false;


	static void threadProc(AsynchronousLoop * object, void(*funcToLoop)(void*), void* funcParam, DWORD millisDelay = 0);

public:
	AsynchronousLoop();
	~AsynchronousLoop();
	
	void Start(void(*funcToLoop)(void*), void* funcParam, DWORD millisDelay = 0);
	void Stop();

	bool IsRunning();
};

