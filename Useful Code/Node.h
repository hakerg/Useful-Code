#pragma once
#include <list>
#include <memory>
#include <type_traits>
#include "Connection.h"

namespace uc
{

	// node used by DirectedGraph
	class Node
	{

		std::list<std::shared_ptr<Connection>> _outcoming_connections;
		std::list<std::shared_ptr<Connection>> _incoming_connections;

	public:

		Node();
		virtual ~Node();

		// get list of outcoming connections
		const std::list<std::shared_ptr<Connection>> & outcoming_connections() const;

		// get list of incoming connections
		const std::list<std::shared_ptr<Connection>> & incoming_connections() const;

		// get iterator to the connection
		typename std::list<std::shared_ptr<Connection>>::iterator find_outcoming_connection(std::shared_ptr<Connection> connection);

		// get iterator to the connection
		typename std::list<std::shared_ptr<Connection>>::iterator find_incoming_connection(std::shared_ptr<Connection> connection);

		// construct and add connection
		template <class _Connection, class... _Args>
		static std::enable_if_t<std::is_base_of_v<Connection, _Connection>> connect(_Args... args)
		{
			std::shared_ptr<Connection> connection = std::make_shared<_Connection>(args...);
			connection->k_source->_outcoming_connections.push_back(connection);
			connection->k_target->_incoming_connections.push_back(connection);
		}

		// destroy connection
		static void disconnect(std::shared_ptr<Connection> connection);

		// _Node must inherit from Node
		// use it only if you are sure of the type
		template <class _Node>
		std::enable_if_t<std::is_base_of_v<Node, _Node>, _Node>* cast()
		{
			return (_Node*)this;
		}

	};

}