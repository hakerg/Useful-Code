#include "Window.h"
#include <algorithm>
#include "LoopedThread.h"



bool Window::_push_next_sub_frame()
{

	if (add_time(_sub_frame_pusher->period) && _event_handler->running)
	{

		if (visible)
		{

			if (dropping_frames_allowed)
			{
				if (!sub_frame_buffer.full())
				{
					auto copy = _get_copied_drawable();
					sub_frame_buffer.try_push(copy);
				}
			}
			else
			{
				auto copy = _get_copied_drawable();
				while (!sub_frame_buffer.try_push(copy)) std::this_thread::yield();
			}

		}

		return true;

	}
	else return false;
}

bool Window::_draw_frame()
{

	if (_sub_frame_pusher->running)
	{

		if (sub_frame_buffer.empty()) std::this_thread::yield();
		else
		{

			unsigned sub_frames = sub_frame_buffer.size();

			sub_frame_buffer.front()->draw(this);
			sub_frame_buffer.try_pop();

			if (sub_frames > 1)
			{

				if (!_temp_image) _temp_image = _create_buffer_image();
				else if (_temp_image->size() != size()) _temp_image = _create_buffer_image();

				float max_divider = std::min((float)sub_frames, 256.0f);
				for (float divider = 2.0f; divider <= max_divider; divider++)
				{
					sub_frame_buffer.front()->draw(&*_temp_image);
					sub_frame_buffer.try_pop();
					_temp_image->draw(this, 1.0f / divider);
				}

			}

			_finish_frame();
		}

		return true;
	}
	else
	{
		sub_frame_buffer.clear();
		return false;
	}

}

Window::Window(unsigned _buffered_frames) :
	sub_frame_buffer(_buffered_frames)
{
}


Window::~Window()
{
}

void Window::run(std::chrono::duration<double> sub_frame_period)
{
	_event_handler = std::make_shared<LoopedThread>(std::chrono::duration<double>::zero(), false, this, &Window::_parse_event);

	_sub_frame_pusher = std::make_shared<LoopedThread>(sub_frame_period, true, this, &Window::_push_next_sub_frame);

	while (_draw_frame());

	_sub_frame_pusher.reset();
	_event_handler.reset();

}

std::chrono::duration<double> Window::frame_period(double fps)
{
	return std::chrono::duration<double>(1.0 / fps);
}

std::chrono::duration<double> Window::sub_frame_period(double fps) const
{
	return std::chrono::duration<double>(1.0 / (fps * sub_frame_buffer.max_size));
}
