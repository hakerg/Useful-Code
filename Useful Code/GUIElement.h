#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"
#include "Figure2D.h"

namespace uc
{

	template <class _DrawTarget, class _PositionNumeric>
	class GUIElement : public Drawable<_DrawTarget>
	{

		// what should happen when click occurs
		virtual void _on_click(const Vector2D<_PositionNumeric> & position) = 0;

		// draw without childs
		virtual void _draw_self(_DrawTarget & target) const = 0;

	public:

		std::shared_ptr<Figure2D<_PositionNumeric>> shape;
		std::vector<std::shared_ptr<GUIElement<_DrawTarget, _PositionNumeric>>> childs;

		// shape - figure used to determine if cursor is over the element
		GUIElement(std::shared_ptr<Figure2D<_PositionNumeric>> shape_) : shape(shape_) {}
		virtual ~GUIElement() {}

		// click event handled
		bool click(const Vector2D<_PositionNumeric> & position)
		{
			for (auto rit = childs.rbegin(); rit != childs.rend(); rit++) if ((*rit)->click(position)) return true;
			if (shape->over(position))
			{
				_on_click(position);
				return true;
			}
			else return false;
		}

		// draws whole element
		void draw(_DrawTarget & target) override
		{
			_draw_self(target);
			for (auto& child : childs) child->draw(target);
		}

	};

}