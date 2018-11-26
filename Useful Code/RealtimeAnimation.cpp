#include "RealtimeAnimation.h"
#include "ThreadLoop.h"



bool RealtimeAnimation::pusherFunc(RealtimeAnimation * object)
{

	object->frame = object->frame->GetNextFrame();
	while (!object->frameToDraw.TryPush(object->frame)) Sleep(1);

	return (bool)object->frame;

}

RealtimeAnimation::RealtimeAnimation() : frameToDraw(1)
{
}


RealtimeAnimation::~RealtimeAnimation()
{
}

void RealtimeAnimation::Run(std::shared_ptr<Animatable> preFirstFrame, double framePeriod_ms)
{

	frame = preFirstFrame;
	ThreadLoop pusher(framePeriod_ms, pusherFunc, this);

	while (true)
	{

		while (frameToDraw.Empty()) Sleep(1);

		auto tempFrame = frameToDraw.Pop();
		if (!tempFrame) break;

		tempFrame->Draw();

	}
}
