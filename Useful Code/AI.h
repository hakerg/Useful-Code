#pragma once
#include "State.h"

namespace uc
{

	// _State - current situation state
	// _Turn - class representing a single turn
	template <class _State, class _Turn>
	class AI
	{
	public:
		AI() {}
		virtual ~AI() {}

		// get best possible turn based on the given situation
		virtual _Turn best_turn(const _State& state) = 0;

	};

}