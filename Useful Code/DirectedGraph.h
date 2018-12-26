#pragma once
#include <type_traits>
#include "Connection.h"
#include "Node.h"

class DirectedGraph : public std::list<std::shared_ptr<Node>>
{
public:

	DirectedGraph();
	virtual ~DirectedGraph();

	// _Node must inherit from Node
	template <class _Node, class... _Args>
	std::enable_if_t<std::is_base_of_v<Node, _Node>> add_node(_Args... args)
	{
		push_back(std::make_shared<_Node>(args...));
	}

};