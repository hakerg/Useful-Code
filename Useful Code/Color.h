#pragma once


template <class _Numeric, unsigned red_position, unsigned green_position, unsigned blue_position, int alpha_position = -1>
class Color
{
public:

	_Numeric data[4];

	Color(const _Numeric& _red, const _Numeric& _green, const _Numeric& _blue, const _Numeric& _alpha)
	{
		red() = _red;
		green() = _green;
		blue() = _blue;
		alpha() = _alpha;
	}
	virtual ~Color() {}

	_Numeric & red() { return data[red_position]; }
	_Numeric & green() { return data[green_position]; }
	_Numeric & blue() { return data[blue_position]; }
	_Numeric & alpha() { return data[alpha_position]; }

	template <class _NewNumeric, unsigned new_red_position, unsigned new_green_position, unsigned new_blue_position, unsigned new_alpha_position>
	Color<_NewNumeric, new_red_position, new_green_position, new_blue_position, new_alpha_position> cast()
	{
		return Color<_NewNumeric, new_red_position, new_green_position, new_blue_position, new_alpha_position>(red(), green(), blue(), alpha());
	}
};


template <class _Numeric, unsigned red_position, unsigned green_position, unsigned blue_position>
class Color<_Numeric, red_position, green_position, blue_position, -1>
{
public:

	_Numeric data[3];

	Color(const _Numeric& _red, const _Numeric& _green, const _Numeric& _blue)
	{
		red() = _red;
		green() = _green;
		blue() = _blue;
	}
	virtual ~Color() {}

	_Numeric & red() { return data[red_position]; }
	_Numeric & green() { return data[green_position]; }
	_Numeric & blue() { return data[blue_position]; }

	template <class _NewNumeric, unsigned new_red_position, unsigned new_green_position, unsigned new_blue_position, unsigned new_alpha_position>
	Color<_NewNumeric, new_red_position, new_green_position, new_blue_position, new_alpha_position> cast()
	{
		return Color<_NewNumeric, new_red_position, new_green_position, new_blue_position, new_alpha_position>(red(), green(), blue(), 1.0);
	}

	template <class _NewNumeric, unsigned new_red_position, unsigned new_green_position, unsigned new_blue_position>
	Color<_NewNumeric, new_red_position, new_green_position, new_blue_position> cast()
	{
		return Color<_NewNumeric, new_red_position, new_green_position, new_blue_position>(red(), green(), blue());
	}
};


typedef Color<unsigned char, 0, 1, 2> ColorRGB;
typedef Color<unsigned char, 2, 1, 0> ColorBGR;
typedef Color<unsigned char, 0, 1, 2, 3> ColorRGBA;
typedef Color<unsigned char, 2, 1, 0, 3> ColorBGRA;
typedef Color<unsigned char, 1, 2, 3, 0> ColorARGB;
typedef Color<unsigned char, 3, 2, 1, 0> ColorABGR;
typedef Color<float, 0, 1, 2> ColorFloatRGB;
typedef Color<float, 2, 1, 0> ColorFloatBGR;
typedef Color<float, 0, 1, 2, 3> ColorFloatRGBA;
typedef Color<float, 2, 1, 0, 3> ColorFloatBGRA;
typedef Color<float, 1, 2, 3, 0> ColorFloatARGB;
typedef Color<float, 3, 2, 1, 0> ColorFloatABGR;
