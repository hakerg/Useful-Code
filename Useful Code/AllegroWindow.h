#pragma once
#include <allegro5/allegro.h>
#include "Vector2D.h"
#include "Window.h"

class AllegroWindow : public Window
{

	bool _acknowledge_drawing_halt = false;

	ALLEGRO_EVENT_QUEUE * _queue;

	virtual bool _parse_event() override; // thread #1
	virtual void _finish_frame() override; // main thread
	virtual std::shared_ptr<Image> _create_buffer_image() const override; // main thread
	virtual void _set_target() const override; // main thread

	virtual bool _handle_event(const ALLEGRO_EVENT & event) = 0; // thread #1

public:

	ALLEGRO_DISPLAY * const k_display;


	AllegroWindow(const Vector2D<unsigned> & _size, unsigned _buffered_frames);
	virtual ~AllegroWindow();

	virtual Vector2D<unsigned> size() const override;
	unsigned framerate() const;

};

