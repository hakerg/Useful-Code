#pragma once
#include <memory>
#include <vector>
#include "Figure2D.h"

namespace uc
{

	// group of figures
	// use it to treat all stored figures as one object
	template <class _Numeric> class Mesh2D :
		public Figure2D<_Numeric>, public std::vector<std::shared_ptr<Figure2D<_Numeric>>>
	{
	public:

		Mesh2D() {}
		virtual ~Mesh2D() {}

		// excluding border
		bool inside(const Vector2D<_Numeric>& point) const override
		{
			for (auto& child : *this) if (child->inside(point)) return true;
			return false;
		}
		bool on_border(const Vector2D<_Numeric>& point) const override
		{
			for (auto& child : *this) if (child->on_border(point)) return true;
			return false;
		}

		// including border
		bool over(const Vector2D<_Numeric>& point) const override
		{
			for (auto& child : *this) if (child->over(point)) return true;
			return false;
		}
		_Numeric area() const override
		{
			_Numeric ret = 0;
			for (auto& child : *this) ret += child->area();
			return ret;
		}
		_Numeric circumference() const override
		{
			_Numeric ret = 0;
			for (auto& child : *this) ret += child->circumference();
			return ret;
		}
	};

}