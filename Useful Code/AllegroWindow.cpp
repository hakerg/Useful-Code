#include "AllegroWindow.h"
#include "AllegroBitmap.h"


bool AllegroWindow::_parse_event()
{
	
	ALLEGRO_EVENT event;
	if (al_get_next_event(_queue, &event))
	{
		if (event.type == ALLEGRO_EVENT_DISPLAY_RESIZE) al_acknowledge_resize(k_display);
		else if (event.type == ALLEGRO_EVENT_DISPLAY_LOST) visible = false;
		else if (event.type == ALLEGRO_EVENT_DISPLAY_FOUND) visible = true;
		else if (event.type == ALLEGRO_EVENT_DISPLAY_SWITCH_OUT) visible = false;
		else if (event.type == ALLEGRO_EVENT_DISPLAY_SWITCH_IN) visible = true;
		else if (event.type == ALLEGRO_EVENT_DISPLAY_HALT_DRAWING)
		{
			visible = false;
			_acknowledge_drawing_halt = true;
		}
		else if (event.type == ALLEGRO_EVENT_DISPLAY_RESUME_DRAWING)
		{
			visible = true;
			al_acknowledge_drawing_resume(k_display);
		}
		return _handle_event(event);
	}
	else std::this_thread::yield();

	return true;
}

void AllegroWindow::_finish_frame()
{
	al_flip_display();
	if (_acknowledge_drawing_halt)
	{
		al_acknowledge_drawing_halt(k_display);
		_acknowledge_drawing_halt = false;
		while (!visible) std::this_thread::yield();
	}
}

std::shared_ptr<Image> AllegroWindow::_create_buffer_image() const
{
	return std::make_shared<AllegroBitmap>(size());
}

AllegroWindow::AllegroWindow(const Vector2D<unsigned> & _size, unsigned _buffered_frames) :
	Window(_buffered_frames),
	k_display(al_create_display(_size.x, _size.y)),
	_queue(al_create_event_queue())
{
	al_register_event_source(_queue, al_get_display_event_source(k_display));

	al_register_event_source(_queue, al_get_mouse_event_source());
	al_register_event_source(_queue, al_get_keyboard_event_source());
	al_register_event_source(_queue, al_get_joystick_event_source());
	al_register_event_source(_queue, al_get_touch_input_event_source());
}


AllegroWindow::~AllegroWindow()
{

	al_destroy_event_queue(_queue);
	al_destroy_display(k_display);

}

void AllegroWindow::_set_target() const
{
	al_set_target_backbuffer(k_display);
}

Vector2D<unsigned> AllegroWindow::size() const
{
	return Vector2D<unsigned>(al_get_display_width(k_display), al_get_display_height(k_display));
}

unsigned AllegroWindow::framerate() const
{
	return al_get_display_refresh_rate(k_display);
}

