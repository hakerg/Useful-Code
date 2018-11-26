#pragma once
#include "Animatable.h"
#include "ThreadDataQueue.h"
class RealtimeAnimation
{

	ThreadDataQueue<std::shared_ptr<Animatable>> frameToDraw;
	std::shared_ptr<Animatable> frame;

	static bool pusherFunc(RealtimeAnimation * object);

public:
	RealtimeAnimation();
	virtual ~RealtimeAnimation();

	void Run(std::shared_ptr<Animatable> preFirstFrame, double framePeriod_ms);
};

