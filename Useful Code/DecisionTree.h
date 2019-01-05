#pragma once
#include <type_traits>
#include <vector>
#include "AI.h"

namespace uc
{

	// _State must inherit from State<_Turn>
	// this class uses algorithm called decision tree to determine best turn
	template <class _State, class _Turn, class _Enable = void>
	class DecisionTree;

	template <class _State, class _Turn>
	class DecisionTree<_State, _Turn, std::enable_if_t<std::is_base_of_v<State<_Turn>, _State>>> :
		public AI<_State, _Turn>
	{
	public:

		unsigned max_steps;
		_State last_best_final_state;

		// if max_steps is zero, then step count is maximum possible value
		DecisionTree(unsigned max_steps_) : max_steps(max_steps_) {}
		virtual ~DecisionTree() {}

		// possible turns for the given state or turns that tree has to check
		// to check one turn multiple times, put many copies of this turn to the container
		// you can use step parameter to determine number of possible turns
		// for example, if step is zero return high number of turns, otherwise return only one
		virtual std::vector<_Turn> possible_turns(const _State & state, unsigned step) const = 0;

		// best_final_state - output - final state with highest fitness
		_Turn best_turn(const _State & state, _State & best_final_state, unsigned step = 0) const
		{

			auto turns = possible_turns(state, step);
			auto best_turn_iterator = turns.end();

			step++;

			for (auto it = turns.begin(); it != turns.end(); it++)
			{

				_State next_state = state;
				next_state.apply_turn(*it);
				_State final_state;
				if (step == max_steps)
				{
					final_state = next_state;
				}
				else
				{
					best_turn(next_state, final_state, step);
				}

				if (best_turn_iterator == turns.end())
				{
					best_turn_iterator = it;
					best_final_state = final_state;
				}
				else if (best_final_state < final_state)
				{
					best_turn_iterator = it;
					best_final_state = final_state;
				}

			}

			return *best_turn_iterator;

		}

		// Odziedziczono za poœrednictwem elementu AI
		_Turn best_turn(const _State & state) override
		{
			return best_turn(state, last_best_final_state);
		}
	};

}