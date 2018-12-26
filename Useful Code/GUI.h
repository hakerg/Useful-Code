#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"
#include "Figure2D.h"

class GUI : public Drawable
{

	virtual void _on_click(const Vector2D<double> & click_position);

	virtual void _draw_self(DrawTarget * target, float alpha) const;

	// Odziedziczono za poœrednictwem elementu Drawable
	virtual void _draw(DrawTarget * target, float alpha) const override;

public:

	std::vector<std::shared_ptr<GUI>> gui_elements;


	GUI();
	virtual ~GUI();

	bool click(const Vector2D<double> & click_position);

	bool over_any_child(const Vector2D<double> & position) const;

	bool over_self_or_any_child(const Vector2D<double> & position) const;

	virtual Figure2D<double> * shape() const;

};

