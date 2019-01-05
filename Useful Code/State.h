#pragma once

namespace uc
{

	// class used by AI
	// contains information about some situation
	// _Turn - turn; can be applied to the State
	template <class _Turn>
	class State
	{
	public:
		State() {}
		virtual ~State() {}

		// set new state based on player's turn
		virtual void apply_turn(const _Turn& turn) = 0;

		// compare fitnesses
		// returns true if state on the right is better for the player
		virtual bool operator < (const State<_Turn>& rhs) const = 0;

	};

}