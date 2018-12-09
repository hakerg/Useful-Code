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

		auto free = (queue.size() < MaxSize);
		if (free)
		{
			queueMutex.lock();
			queue.push(value);
			queueMutex.unlock();
		}
		
		return free;
	}


	void ForcePush(const T & value)
	{
		queueMutex.lock();
		queue.push(value);
		while (queue.size() > MaxSize) queue.pop();

		queueMutex.unlock();

	}


	bool TryPop()
	{
		queueMutex.lock();

		bool ret = queue.size();
		if (ret)
		{
			queue.pop();
		}

		queueMutex.unlock();
		return ret;
	}

	bool TryPop(T & output)
	{
		queueMutex.lock();

		bool ret = queue.size();
		if (ret)
		{
			output = queue.front();
			queue.pop();
		}

		queueMutex.unlock();
		return ret;
	}

	T & Front()
	{
		queueMutex.lock();

		T & ret = queue.front();

		queueMutex.unlock();
		return ret;
	}

	
	bool Empty() const
	{
		return queue.empty();
	}


	unsigned Size() const
	{
		return queue.size();
	}


	bool Full() const
	{
		return Size() >= MaxSize;
	}
};
