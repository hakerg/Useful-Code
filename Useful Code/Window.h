#pragma once
#include <memory>
#include "Image.h"
#include "LoopedThread.h"
#include "ThreadDataQueue.h"
#include "TimeDependent.h"

class Window :
	public TimeDependent, public DrawTarget
{

	bool _push_next_sub_frame(); // thread #2
	bool _draw_frame(); // main thread

	virtual bool _parse_event() = 0; // thread #1
	virtual void _finish_frame() = 0; // main thread
	virtual std::shared_ptr<Drawable> _get_copied_drawable() const = 0; // thread #2
	virtual std::shared_ptr<Image> _create_buffer_image() const = 0; // main thread

	std::shared_ptr<Image> _temp_image;
	std::shared_ptr<LoopedThread> _event_handler, _sub_frame_pusher;

public:
	ThreadDataQueue<std::shared_ptr<Drawable>> sub_frame_buffer;
	bool dropping_frames_allowed = false;
	bool visible = true;


	Window(unsigned _buffered_frames);
	virtual ~Window();

	void run(std::chrono::duration<double> sub_frame_period);

	static std::chrono::duration<double> frame_period(double fps);
	std::chrono::duration<double> sub_frame_period(double fps) const;
};
