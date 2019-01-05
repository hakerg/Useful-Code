#pragma once
#include <type_traits>
#include "Connection.h"
#include "Node.h"

namespace uc
{

	// to make graph undirected, for each connection add two connection objects -
	// - the first one from A to B and the second one from B to A
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

}