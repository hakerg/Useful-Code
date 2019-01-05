#pragma once
#include "Figure2D.h"
#include "math_defines.h"
#include "Vector2D.h"

namespace uc
{

	class Circle :
		public Figure2D<double>
	{
	public:

		Vector2D<double> center;
		double radius;


		Circle(const Vector2D<double> & center_, double radius_);

		// creates circle where all of three points lie on the circle
		Circle(const Vector2D<double> & p1_, const Vector2D<double> & p2_, const Vector2D<double> & p3_);
		virtual ~Circle();

		// excluding border
		bool inside(const Vector2D<double>& point) const override;

		bool on_border(const Vector2D<double>& point) const override;

		// including border
		bool over(const Vector2D<double>& point) const override;

		double area() const override;
		double circumference() const override;
	};

}