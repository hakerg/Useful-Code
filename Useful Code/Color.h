#pragma once

namespace uc
{

	// this class can be used to represent any possible color format with any data type
	// you can easily convert any color data pointer to an array of this objects
	// supports both transparent and non-transparent colors
	template <class _Numeric, unsigned _red_position, unsigned _green_position, unsigned _blue_position, int _alpha_position = -1>
	class Color
	{
	public:

		_Numeric data[4];

		Color(const _Numeric& red_, const _Numeric& green_, const _Numeric& blue_, const _Numeric& alpha_)
		{
			red() = red_;
			green() = green_;
			blue() = blue_;
			alpha() = alpha_;
		}
		virtual ~Color() {}

		_Numeric & red() { return data[_red_position]; }
		_Numeric & green() { return data[_green_position]; }
		_Numeric & blue() { return data[_blue_position]; }
		_Numeric & alpha() { return data[_alpha_position]; }

		template <class _NewNumeric, unsigned _new_red_position, unsigned _new_green_position, unsigned _new_blue_position, unsigned _new_alpha_position>
		Color<_NewNumeric, _new_red_position, _new_green_position, _new_blue_position, _new_alpha_position> cast()
		{
			return { red(), green(), blue(), alpha() };
		}
	};

	template <class _Numeric, unsigned _red_position, unsigned _green_position, unsigned _blue_position>
	class Color<_Numeric, _red_position, _green_position, _blue_position, -1>
	{
	public:

		_Numeric data[3];

		Color(const _Numeric& red_, const _Numeric& green_, const _Numeric& blue_)
		{
			red() = red_;
			green() = green_;
			blue() = blue_;
		}
		virtual ~Color() {}

		_Numeric & red() { return data[_red_position]; }
		_Numeric & green() { return data[_green_position]; }
		_Numeric & blue() { return data[_blue_position]; }

		template <class _NewNumeric, unsigned _new_red_position, unsigned _new_green_position, unsigned _new_blue_position, unsigned _new_alpha_position>
		Color<_NewNumeric, _new_red_position, _new_green_position, _new_blue_position, _new_alpha_position> cast()
		{
			return { red(), green(), blue(), 1.0 };
		}

		template <class _NewNumeric, unsigned _new_red_position, unsigned _new_green_position, unsigned _new_blue_position>
		Color<_NewNumeric, _new_red_position, _new_green_position, _new_blue_position> cast()
		{
			return { red(), green(), blue() };
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

}