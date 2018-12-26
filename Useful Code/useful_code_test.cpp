#include <allegro5\allegro_primitives.h>
#include <iostream>
#include "DecisionTree.h"


class TestState : public State<int>
{
public:
	// Odziedziczono za poœrednictwem elementu State
	virtual void apply_turn(const int & turn) override
	{
	}
	virtual bool operator<(const State<int>& rhs) const override
	{
		return false;
	}
};


class TestTree : public DecisionTree<TestState, int>
{
public:

	TestTree() : DecisionTree<TestState, int>(0) {}

	// Odziedziczono za poœrednictwem elementu RandomTree
	virtual std::vector<int> possible_turns(const TestState & state) const override
	{
		return std::vector<int>();
	}
};


int main()
{
	al_init();
	al_install_keyboard();
	al_install_mouse();
	al_install_joystick();
	al_install_touch_input();
	al_init_primitives_addon();

	al_set_new_display_flags(ALLEGRO_OPENGL | ALLEGRO_RESIZABLE);
	al_set_new_display_option(ALLEGRO_VSYNC, 1, ALLEGRO_SUGGEST);

	TestTree tree;

	system("PAUSE");

	return 0;
} 