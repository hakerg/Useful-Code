#include "GUI.h"

void GUI::_on_click(const Vector2D<double>& click_position)
{
}

void GUI::_draw_self(DrawTarget * target, float alpha) const
{
}

GUI::GUI() {}

GUI::~GUI() {}

bool GUI::click(const Vector2D<double>& click_position)
{

	for (auto& c : gui_elements) if (c->click(click_position)) return true;

	if (shape()->over(click_position))
	{
		_on_click(click_position);
		return true;
	}
	else return false;
}

bool GUI::over_any_child(const Vector2D<double>& position) const
{

	for (auto& c : gui_elements) if (c->over_self_or_any_child(position)) return true;
	return false;

}

bool GUI::over_self_or_any_child(const Vector2D<double>& position) const
{
	return shape()->over(position) || over_any_child(position);
}

Figure2D<double>* GUI::shape() const
{
	return nullptr;
}

void GUI::_draw(DrawTarget * target, float alpha) const
{
	_draw_self(target, alpha);
	for (auto& c : gui_elements) c->draw(target, alpha);
}
