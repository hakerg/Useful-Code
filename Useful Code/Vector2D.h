#pragma once
#include <cmath>
#include <type_traits>

template <class _Numeric> class Vector2D
{
public:

	_Numeric x, y;


	Vector2D(_Numeric _x, _Numeric _y) : x(_x), y(_y) {}
	Vector2D(const Vector2D<_Numeric> & _from, const Vector2D<_Numeric> & _to) : x(_to.x - _from.x), y(_to.y - _from.y) {}
	virtual ~Vector2D() {}

	static Vector2D<_Numeric> FromPolar(double length, double rotation)
	{
		return Vector2D<_Numeric>(length * cos(rotation), length * sin(rotation));
	}

	double length() const { return sqrt(x * x + y * y); }
	double rotation() const { return atan2(y, x); }


	Vector2D<_Numeric> get_rotated(double rotation) const
	{
		_Numeric sin_a = sin(rotation);
		_Numeric cos_a = cos(rotation);
		return Vector2D<_Numeric>(x * cos_a - y * sin_a, x * sin_a + y * cos_a);
	}


	double quadrature() const
	{
		return sqrt(x * y);
	}


	template <class _NumType2> bool operator == (const Vector2D<_NumType2> & rhs) const
	{
		return x == rhs.x && y == rhs.y;
	}

	template <class _NumType2> bool operator != (const Vector2D<_NumType2> & rhs) const
	{
		return !(*this == rhs);
	}

	template <class _NumType2> Vector2D<typename std::common_type<_Numeric, _NumType2>::type> operator + (const Vector2D<_NumType2> & rhs) const
	{
		return Vector2D<typename std::common_type<_Numeric, _NumType2>::type>(x + rhs.x, y + rhs.y);
	}

	template <class _NumType2> Vector2D<typename std::common_type<_Numeric, _NumType2>::type> operator - (const Vector2D<_NumType2> & rhs) const
	{
		return Vector2D<typename std::common_type<_Numeric, _NumType2>::type>(x - rhs.x, y - rhs.y);
	}

	Vector2D<_Numeric> operator * (_Numeric rhs) const
	{
		return Vector2D<_Numeric>(x * rhs, y * rhs);
	}

	template <class _NumType2> Vector2D<typename std::common_type<_Numeric, _NumType2>::type> operator * (const Vector2D<_NumType2> & rhs) const
	{
		return Vector2D<typename std::common_type<_Numeric, _NumType2>::type>(x * rhs.x, y * rhs.y);
	}

	Vector2D<_Numeric> operator / (_Numeric rhs) const
	{
		return Vector2D<_Numeric>(x / rhs, y / rhs);
	}

	template <class _NumType2> Vector2D<typename std::common_type<_Numeric, _NumType2>::type> operator / (const Vector2D<_NumType2> & rhs) const
	{
		return Vector2D<typename std::common_type<_Numeric, _NumType2>::type>(x / rhs.x, y / rhs.y);
	}

	template <class _NewNumType> Vector2D<_NewNumType> cast() const
	{
		return Vector2D<_NewNumType>(x, y);
	}
}; 

