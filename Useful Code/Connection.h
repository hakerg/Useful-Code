#pragma once
#include <type_traits>

namespace uc
{

	class Node;

	// one-directional connection used by DirectedGraph
	class Connection
	{
	public:
		Node * const k_source;
		Node * const k_target;

		Connection(Node * source_, Node * target_);
		virtual ~Connection();

		// _Connection must inherit from Connection
		// use it only if you are sure of the type
		template <class _Connection>
		std::enable_if_t<std::is_base_of_v<Connection, _Connection>, _Connection>* cast()
		{
			return (_Connection*)this;
		}

		// _Node must inherit from Node
		// use it only if you are sure of the type
		template <class _Node>
		std::enable_if_t<std::is_base_of_v<Node, _Node>, _Node>* source() const
		{
			return (_Node*)k_source;
		}

		// _Node must inherit from Node
		// use it only if you are sure of the type
		template <class _Node>
		std::enable_if_t<std::is_base_of_v<Node, _Node>, _Node>* target() const
		{
			return (_Node*)k_target;
		}
	};

}