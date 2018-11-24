#pragma once
#include "Figure2D.h"
#include <vector>
#include <memory>

template <class NumType = double> class Mesh2D :
	public Figure2D<NumType>
{
public:

	std::vector<std::shared_ptr<Mesh2D>> Childs;


	Mesh2D() {}
	~Mesh2D() {}

	// Odziedziczono za poœrednictwem elementu Figure2D
	virtual bool IsInside(const Vector2D<NumType>& point) override
	{
		for (auto& child : Childs) if (child->IsInside(point)) return true;
		return false;
	}
	virtual bool IsOnBorder(const Vector2D<NumType>& point) override
	{
		for (auto& child : Childs) if (child->IsOnBorder(point)) return true;
		return false;
	}
	virtual bool IsOver(const Vector2D<NumType>& point) override
	{
		for (auto& child : Childs) if (child->IsOver(point)) return true;
		return false;
	}
	virtual NumType GetArea() override
	{
		NumType area = 0;
		for (auto& child : Childs) area += child->GetArea();
		return area;
	}
	virtual NumType GetCircumference() override
	{
		NumType circumference = 0;
		for (auto& child : Childs) circumference += child->GetCircumference();
		return circumference;
	}
};

