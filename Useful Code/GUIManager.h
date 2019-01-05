#pragma once
#include <memory>
#include <vector>
#include "Drawable.h"
#include "GUIElement.h"

namespace uc
{

	template <class _DrawTarget, class _PositionNumeric>
	class GUIManager : public Drawable<_DrawTarget>
	{
	public:

		std::vector<std::shared_ptr<GUIElement<_DrawTarget, _PositionNumeric>>> elements;

		GUIManager() {}
		virtual ~GUIManager() {}

		// Odziedziczono za poœrednictwem elementu Drawable
		void draw(_DrawTarget & target) override
		{
			for (auto& element : elements) element->draw(target);
		}

		// call this when click is handled
		void click(const Vector2D<_PositionNumeric> & position)
		{
			for (auto rit = elements.rbegin(); rit != elements.rend(); rit++)
			{
				if ((*rit)->click(position)) return;
			}
		}
	};

}