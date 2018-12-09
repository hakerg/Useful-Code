#include "AllegroWindow.h"
#include <iostream>


bool AllegroWindow::parseEvent()
{
	
	ALLEGRO_EVENT event;
	if (al_wait_for_event_timed(queue, &event, 0.001))
	{
		return handleEvent(event);
	}

	return true;
}

bool AllegroWindow::pushNextFrame(bool * running)
{
	if (SetNextFrame() && *running)
	{

		auto copy = GetCopiedDrawable();
		if (AutoSkipFrames) FrameBuffer.ForcePush(copy);
		else while (!FrameBuffer.TryPush(copy)) Sleep(1);

		return true;

	}
	else return false;
}

bool AllegroWindow::drawFrame(bool * running)
{

	if (FrameBuffer.Empty())
	{
		if (!*running) return false;
		else Sleep(1);
	}
	else
	{

		startFrame();
		float frames = FrameBuffer.Size();

		std::shared_ptr<DrawableTransparently> frame;
		for (float divider = 1.0f; divider <= frames; divider++)
		{
			if (FrameBuffer.TryPop(frame))
			{
				frame->Draw(this, 1.0f / divider);
			}
			else break;
		}

		finishFrame();
	}
	return true;

}

AllegroWindow::AllegroWindow(const Vector2D<unsigned> & size, unsigned bufferedFrames) :
	Display(al_create_display(size.X, size.Y)),
	FrameBuffer(bufferedFrames),
	queue(al_create_event_queue())
{
	al_register_event_source(queue, al_get_display_event_source(Display));

	al_register_event_source(queue, al_get_mouse_event_source());
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_joystick_event_source());
	al_register_event_source(queue, al_get_touch_input_event_source());
}


AllegroWindow::~AllegroWindow()
{

	al_destroy_event_queue(queue);
	al_destroy_display(Display);

}

void AllegroWindow::Run(double framePeriod_ms)
{
	LoopedThread eventHandler(0.0, this, &AllegroWindow::parseEvent);
	LoopedThread pusher(framePeriod_ms, this, &AllegroWindow::pushNextFrame, &eventHandler.Running);

	bool running = true;
	LoopedThread::LoopMethodPeriodically(&running, 0.0, this, &AllegroWindow::drawFrame, &pusher.Running);

}

double AllegroWindow::ToMilliseconds(double fps)
{
	return 1000.0 / fps;
}

Vector2D<unsigned> AllegroWindow::GetSize() const
{
	return Vector2D<unsigned>(al_get_display_width(Display), al_get_display_height(Display));
}

unsigned AllegroWindow::GetFramerate() const
{
	return al_get_display_refresh_rate(Display);
}

Vector2D<float> AllegroWindow::GetPixelPosition(const Vector2D<double>& windowPosition) const
{
	auto size = GetSize();
	return Vector2D<float>(windowPosition.X * size.X, windowPosition.Y * size.Y);
}
