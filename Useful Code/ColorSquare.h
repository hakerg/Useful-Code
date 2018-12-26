#pragma once
#include "Color.h"
#include "Square.h"

template <class _Numeric, class _Color>
class ColorSquare : public Square<_Numeric>, public _Color
{
public:
	ColorSquare() {}
	virtual ~ColorSquare() {}
};
