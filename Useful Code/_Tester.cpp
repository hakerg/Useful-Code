#include <iostream>
#include <Windows.h>
#include "AllegroWindow.h"
#include <allegro5\allegro_primitives.h>


class TestDrawable : public DrawableTransparently
{
public:

	float X = 0;
	ALLEGRO_BITMAP * Temp;

	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void Draw(DrawTarget * target, float alpha) const override
	{
		ALLEGRO_DISPLAY * targetDisplay = ((AllegroWindow*)target)->Display;

		if (alpha < 1.0f)
		{
			al_set_target_bitmap(Temp);
		}
		else
		{
			al_set_target_backbuffer(targetDisplay);
		}

		al_clear_to_color(al_map_rgb_f(1.0f, 1.0f, 1.0f));
		al_draw_rectangle(X, 250.0f, X + 100.0f, 350.0f, al_map_rgb_f(1.0f, 0.0f, 0.0f), 10.0f);
		al_draw_rectangle(X - 800.0f, 250.0f, X - 700.0f, 350.0f, al_map_rgb_f(1.0f, 0.0f, 0.0f), 10.0f);

		if (alpha < 1.0f)
		{
			al_set_target_backbuffer(targetDisplay);
			al_draw_tinted_bitmap(Temp, al_map_rgba_f(alpha, alpha, alpha, alpha), 0, 0, NULL);
		}
	}
};


class Test : public AllegroWindow, public TestDrawable
{
public:

	Test() : AllegroWindow({ 0, 0 })
	{
		auto size = GetSize();
		Temp = al_create_bitmap(size.X, size.Y);
	}

	// Odziedziczono za poœrednictwem elementu AllegroWindow
	virtual bool handleEvent(const ALLEGRO_EVENT & event) override
	{
		if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) return false;
		else if (event.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
			{
				ALLEGRO_KEYBOARD_STATE keyboard;
				al_get_keyboard_state(&keyboard);
				if (al_key_down(&keyboard, ALLEGRO_KEY_ALT)) return false;
			}
		}
		return true;
	}

	// Odziedziczono za poœrednictwem elementu AllegroWindow
	virtual bool SetNextFrame() override
	{
		X++;
		if (X == 800.0f) X = 0.0f;
		return true;
	}
	virtual std::shared_ptr<DrawableTransparently> GetCopiedDrawable() const override
	{
		return std::shared_ptr<DrawableTransparently>(new TestDrawable(*this));
	}

	// Odziedziczono za poœrednictwem elementu AllegroWindowMotionBlur
	virtual void startFrame() override
	{
	}
	virtual void finishFrame() override
	{
		al_flip_display();
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

	al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_FULLSCREEN_WINDOW);
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_REQUIRE);


	Test * window = new Test;
	window->Run();
	delete window;

	return 0;
}