#include "GUIElement.h"



GUIElement::GUIElement(void(*onClick)(GUIElement * sender, const Vector2D<double> & clickPosition)) : OnClick(onClick)
{
}


GUIElement::~GUIElement()
{
}

void GUIElement::CheckClick(const Vector2D<double> & clickPosition)
{

	for (auto& c : ChildElements) if (c->IsOver(clickPosition))
	{
		c->OnClick(&*c, clickPosition);
		return;
	}
	if (IsOver(clickPosition)) OnClick(this, clickPosition);

}

