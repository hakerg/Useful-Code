#include <allegro5\allegro_primitives.h>
#include <iostream>
#include "AnimationQuarterSine.h"
#include "AllegroWindow.h"
#include "Circle.h"
#include "TimeManager.h"
#include "Transformation.h"

using namespace uc;

class TestDrawData
{
public:

	Vector2D<double> p1, p2, p3;

	TestDrawData() : p1(-0.25, -0.25), p2(0.3, -0.3), p3(0.0, 0.0) {}

};


class TestWindow : public AllegroWindow<TestDrawData>
{
public:

	double normalized_side = 1.0;
	Rectangle<double> normalized_bounds = Rectangle<double>(Vector2D<double>::zeros(), { normalized_side, normalized_side });
	Vector2D<double> cursor = Vector2D<double>(0.0, 0.0);
	TimeManager animation_manager;
	std::mutex animation_manager_mutex;

	TestWindow() : AllegroWindow<TestDrawData>({600, 600}, 8) {}

	void draw(const TestDrawData & source) override
	{
		al_clear_to_color(al_map_rgb(255, 255, 255));
		Circle circle(source.p1, source.p2, source.p3);
		auto center = Transformation::fit_position(circle.center, normalized_bounds, min_bounds());
		auto p1 = Transformation::fit_position(source.p1, normalized_bounds, min_bounds());
		auto p2 = Transformation::fit_position(source.p2, normalized_bounds, min_bounds());
		auto p3 = Transformation::fit_position(source.p3, normalized_bounds, min_bounds());
		auto radius = Transformation::fit_dimension(circle.radius, normalized_side, min_dimension());
		auto thickness = Transformation::fit_dimension(0.003, normalized_side, min_dimension());
		al_draw_circle(center.x, center.y, radius, al_map_rgb(255, 0, 0), thickness);
		al_draw_filled_circle(p1.x, p1.y, thickness * 2.0, al_map_rgb(0, 255, 255));
		al_draw_filled_circle(p2.x, p2.y, thickness * 2.0, al_map_rgb(0, 255, 255));
		al_draw_filled_circle(p3.x, p3.y, thickness * 2.0, al_map_rgb(0, 0, 0));
	}

	// Odziedziczono za poœrednictwem elementu AllegroWindow
	bool add_time(std::chrono::duration<double> delta_time) override
	{
		animation_manager_mutex.lock();
		animation_manager.add_time(delta_time);
		animation_manager_mutex.unlock();
		current_frame.p3 = cursor;
		return true;
	}
	bool _handle_event(const ALLEGRO_EVENT & event) override
	{
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return false;
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN) return false;
		else if (event.type == ALLEGRO_EVENT_MOUSE_AXES)
		{
			auto delta_cursor = Vector2D<double>(cursor, Transformation::fit_position(Vector2D<int>(event.mouse.x, event.mouse.y), min_bounds(), normalized_bounds));
			animation_manager_mutex.lock();
			animation_manager.push_back(std::make_shared<AnimationQuarterSine>(cursor.x, delta_cursor.x, std::chrono::duration<double>(1.0 / 60.0)));
			animation_manager.push_back(std::make_shared<AnimationQuarterSine>(cursor.y, delta_cursor.y, std::chrono::duration<double>(1.0 / 60.0)));
			animation_manager_mutex.unlock();
		}
		return true;
	}
};


int main()
{
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_install_joystick();
	al_install_touch_input();
	al_init_primitives_addon();

	al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_RESIZABLE);
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);
	al_set_new_display_refresh_rate(60);

	TestWindow * window = new TestWindow;
	al_hide_mouse_cursor(window->k_display);
	window->run(window->sub_frame_period(60.0));
	delete window;

	//system("PAUSE");

	return 0;
} 