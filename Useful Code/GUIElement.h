#pragma once
#include "Mesh2D.h"
#include <vector>
#include <memory>

class GUIElement :
	public Mesh2D<double>
{
public:

	std::vector<std::shared_ptr<GUIElement>> ChildElements;
	void(*OnClick)(GUIElement * sender, const Vector2D<double> & clickPosition);


	GUIElement(void(*onClick)(GUIElement * sender, const Vector2D<double> & clickPosition));
	virtual ~GUIElement();

	void CheckClick(const Vector2D<double> & clickPosition);
};

