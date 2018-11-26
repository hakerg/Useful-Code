#pragma once
#include <queue>
#include <mutex>

template <class T> class ThreadDataQueue
{

	std::queue<T> queue;
	std::mutex queueMutex;

public:

	unsigned MaxSize;


	ThreadDataQueue(unsigned maxSize) : MaxSize(maxSize) {}
	virtual ~ThreadDataQueue() {}


	bool TryPush(const T & value)
	{
		queueMutex.lock();

		bool free = queue.size() < MaxSize;
		if (free) queue.push(value);
		
		queueMutex.unlock();
		return free;
	}


	T Pop()
	{
		queueMutex.lock();

		T ret = queue.front();
		queue.pop();

		queueMutex.unlock();
		return ret;
	}

	
	bool Empty()
	{
		queueMutex.lock();

		bool ret = queue.empty();

		queueMutex.unlock();
		return ret;
	}


	unsigned Size()
	{
		queueMutex.lock();

		unsigned ret = queue.size();

		queueMutex.unlock();
		return ret;
	}


	bool Full()
	{
		return Size() >= MaxSize;
	}
};
