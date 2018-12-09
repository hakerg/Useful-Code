#pragma once
#include <allegro5/allegro.h>
#include "LoopedThread.h"
#include "ThreadDataQueue.h"
#include "DrawableTransparently.h"
#include "Animation.h"
#include "DrawTarget.h"
#include "Vector2D.h"

class AllegroWindow : public Animation, public DrawTarget
{

	ALLEGRO_EVENT_QUEUE * queue;

	bool parseEvent();

	virtual bool handleEvent(const ALLEGRO_EVENT & event) = 0;
	bool pushNextFrame(bool * running);
	virtual bool drawFrame(bool * running);

protected:

	virtual void startFrame() = 0;
	virtual void finishFrame() = 0;

public:

	ALLEGRO_DISPLAY * const Display;
	ThreadDataQueue<std::shared_ptr<DrawableTransparently>> FrameBuffer;
	bool AutoSkipFrames = false;


	AllegroWindow(const Vector2D<unsigned> & size, unsigned bufferedFrames = 1);
	virtual ~AllegroWindow();

	void Run(double framePeriod_ms = 0);
	virtual std::shared_ptr<DrawableTransparently> GetCopiedDrawable() const = 0;

	static double ToMilliseconds(double fps);


	Vector2D<unsigned> GetSize() const;
	unsigned GetFramerate() const;
	Vector2D<float> GetPixelPosition(const Vector2D<double> & windowPosition) const;

};

