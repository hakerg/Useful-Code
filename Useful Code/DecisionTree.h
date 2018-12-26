#pragma once
#include <type_traits>
#include <vector>
#include "AI.h"

// _State must inherit from State<_Turn>
template <class _State, class _Turn, class _Enable = void>
class DecisionTree;

template <class _State, class _Turn>
class DecisionTree<_State, _Turn, std::enable_if_t<std::is_base_of_v<State<_Turn>, _State>>> :
	public AI<_State, _Turn>
{
public:

	unsigned max_steps;
	_State last_best_final_state;


	DecisionTree(unsigned _max_steps) : max_steps(_max_steps) {}
	virtual ~DecisionTree() {}


	virtual std::vector<_Turn> possible_turns(const _State & state) const = 0;

	_Turn best_turn(const _State & state, unsigned steps, _State & _out_best_final_state) const
	{

		steps--;

		auto turns = possible_turns(state);
		auto best_turn_iterator = turns.end();

		for (auto it = turns.begin(); it != turns.end(); it++)
		{

			_State next_state = state;
			next_state.apply_turn(*it);
			_State final_state;
			if (steps)
			{
				best_turn(next_state, steps, final_state);
			}
			else
			{
				final_state = next_state;
			}

			if (best_turn_iterator == turns.end())
			{
				best_turn_iterator = it;
				_out_best_final_state = final_state;
			}
			else if (_out_best_final_state < final_state)
			{
				best_turn_iterator = it;
				_out_best_final_state = final_state;
			}

		}

		return *best_turn_iterator;

	}

	// Odziedziczono za poœrednictwem elementu AI
	virtual _Turn best_turn(const _State & state) override
	{
		return best_turn(state, max_steps, last_best_final_state);
	}
};
