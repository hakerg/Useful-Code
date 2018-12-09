#pragma once
#include "Figure2D.h"
#include <vector>
#include <memory>

template <class NumType = double> class Mesh2D :
	public Figure2D<NumType>
{
public:

	std::vector<std::shared_ptr<Mesh2D<NumType>>> ChildFigures;


	Mesh2D() {}
	virtual ~Mesh2D() {}

	// Odziedziczono za poœrednictwem elementu Figure2D
	virtual bool IsInside(const Vector2D<NumType>& point) const override
	{
		for (auto& child : ChildFigures) if (child->IsInside(point)) return true;
		return false;
	}
	virtual bool IsOnBorder(const Vector2D<NumType>& point) const override
	{
		for (auto& child : ChildFigures) if (child->IsOnBorder(point)) return true;
		return false;
	}
	virtual bool IsOver(const Vector2D<NumType>& point) const override
	{
		for (auto& child : ChildFigures) if (child->IsOver(point)) return true;
		return false;
	}
	virtual NumType GetArea() const override
	{
		NumType area = 0;
		for (auto& child : ChildFigures) area += child->GetArea();
		return area;
	}
	virtual NumType GetCircumference() const override
	{
		NumType circumference = 0;
		for (auto& child : ChildFigures) circumference += child->GetCircumference();
		return circumference;
	}
};

