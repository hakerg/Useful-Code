#pragma once

namespace uc
{

	template <class _DrawTarget>
	class Drawable
	{
	public:

		virtual void draw(_DrawTarget & target) = 0;

		Drawable() {}
		virtual ~Drawable() {}
	};

}