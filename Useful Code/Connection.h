#pragma once
#include <type_traits>

class Node;

class Connection
{
public:
	Node * const k_source;
	Node * const k_target;

	Connection(Node * _source, Node * _target);
	virtual ~Connection();

	// _Connection must inherit from Connection
	template <class _Connection>
	std::enable_if_t<std::is_base_of_v<Connection, _Connection>, _Connection>* cast()
	{
		return (_Connection*)this;
	}

	// _Node must inherit from Node
	template <class _Node>
	std::enable_if_t<std::is_base_of_v<Node, _Node>, _Node>* source() const
	{
		return (_Node*)k_source;
	}

	// _Node must inherit from Node
	template <class _Node>
	std::enable_if_t<std::is_base_of_v<Node, _Node>, _Node>* target() const
	{
		return (_Node*)k_target;
	}
};