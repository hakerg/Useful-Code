#pragma once

template <class _Turn>
class State
{
public:
	State() {}
	virtual ~State() {}

	virtual void apply_turn(const _Turn& turn) = 0;
	virtual bool operator < (const State<_Turn>& rhs) const = 0; // compare fitnesses

};
