#pragma once
#include <vector>
#include "Vector2D.h"

namespace uc
{

	// easy to use 2D container
	template <class _Type>
	class Array2D : public std::vector<_Type>
	{
	public:

		unsigned columns;

		Array2D(unsigned columns_) : columns(columns_) {}

		Array2D(const Vector2D<unsigned> & size_, const _Type & value_) :
			columns(size_.x), std::vector<_Type>(size_.x * size_.y, value_) {}

		template <class _InputIterator> Array2D(unsigned columns_, _InputIterator first_, _InputIterator last_) :
			columns(columns_), std::vector<_Type>(first_, last_) {}

		virtual ~Array2D() {}


		Vector2D<unsigned> size2d() const
		{
			return { columns, this->size() / columns };
		}

		void resize2d(const Vector2D<unsigned> & new_size)
		{
			columns = new_size.x;
			this->resize(new_size.x * new_size.y);
		}

		void resize2d(const Vector2D<unsigned> & new_size, const _Type & value)
		{
			columns = new_size.x;
			this->resize(new_size.x * new_size.y, value);
		}

		unsigned calculate_index(const Vector2D<unsigned> & position) const
		{
			return position.y * columns + position.x;
		}

		Vector2D<unsigned> calculate_position2d(unsigned index) const
		{
			return { index % columns, index / columns };
		}

		_Type & operator[] (const Vector2D<unsigned> & position)
		{
			return (*this)[calculate_index(position)];
		}

		const _Type & operator[] (const Vector2D<unsigned> & position) const
		{
			return (*this)[calculate_index(position)];
		}

		_Type & at(const Vector2D<unsigned> & position)
		{
			return this->at(calculate_index(position));
		}

		const _Type & at(const Vector2D<unsigned> & position) const
		{
			return this->at(calculate_index(position));
		}
	};

}