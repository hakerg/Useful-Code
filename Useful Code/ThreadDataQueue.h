#pragma once
#include <mutex>
#include <queue>

template <class _Type> class ThreadDataQueue
{

	std::queue<_Type> _queue;
	std::mutex _queue_mutex;

public:

	unsigned max_size;


	ThreadDataQueue(unsigned _max_size) : max_size(_max_size) {}
	virtual ~ThreadDataQueue() {}


	void clear()
	{

		std::queue<_Type> empty;
		std::lock_guard<std::mutex> lock(_queue_mutex);

		_queue = empty;

	}
	

	bool try_push(const _Type & value)
	{

		if (_queue.size() >= max_size) return false;

		std::lock_guard<std::mutex> lock(_queue_mutex);
		_queue.push(value);
		
		return true;
	}


	bool try_pop()
	{
		std::lock_guard<std::mutex> lock(_queue_mutex);

		if (_queue.size())
		{
			_queue.pop();
			return true;
		}
		else return false;
	}

	bool try_pop(_Type & _out_value)
	{
		std::lock_guard<std::mutex> lock(_queue_mutex);

		if (_queue.size())
		{
			_out_value = _queue.front();
			_queue.pop();
			return true;
		}
		else return false;
	}

	_Type & front()
	{
		std::lock_guard<std::mutex> lock(_queue_mutex);

		return _queue.front();
	}

	
	bool empty() const
	{
		return _queue.empty();
	}


	unsigned size() const
	{
		return _queue.size();
	}


	bool full() const
	{
		return size() >= max_size;
	}
};
