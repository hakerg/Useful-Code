#pragma once
#include "State.h"

template <class _State, class _Turn>
class AI
{
public:
	AI() {}
	virtual ~AI() {}

	virtual _Turn best_turn(const _State& state) = 0;

};
