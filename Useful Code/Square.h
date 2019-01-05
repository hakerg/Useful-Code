#pragma once
#include <cmath>
#include "Figure2D.h"
#include "Rectangle.h"
#include "Vector2D.h"

namespace uc
{

	// be careful about constructor parameters
	template <class _Numeric> class Square :
		public Figure2D<_Numeric>
	{
	public:

		Vector2D<_Numeric> center;
		_Numeric side;


		// center - the center of the square / point where diagonals cross
		// half_size - vector pointed from center to the edge
		Square(const Vector2D<_Numeric> & center_, _Numeric side_) : center(center_), side(side_) {}
		virtual ~Square() {}

		Vector2D<double> top_left() const
		{
			return { center.x - side * 0.5, center.y - side * 0.5 };
		}

		Vector2D<double> bottom_right() const
		{
			return { center.x + side * 0.5, center.y + side * 0.5 };
		}

		// excluding border
		bool inside(const Vector2D<_Numeric>& point) const override
		{
			return abs(point.x - center.x) * 2 < side && abs(point.y - center.y) * 2 < side;
		}
		bool on_border(const Vector2D<_Numeric>& point) const override
		{
			return abs(point.x - center.x) * 2 == side && abs(point.y - center.y) * 2 == side;
		}

		// including border
		bool over(const Vector2D<_Numeric>& point) const override
		{
			return abs(point.x - center.x) * 2 <= side && abs(point.y - center.y) * 2 <= side;
		}
		_Numeric area() const override
		{
			return side * side;
		}
		_Numeric circumference() const override
		{
			return side * 4;
		}

		Rectangle<_Numeric> rectange() const
		{
			return { center, {side, side} };
		}
	};

}