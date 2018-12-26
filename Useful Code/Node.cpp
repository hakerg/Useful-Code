#include "Node.h"
#include <algorithm>
#include "Connection.h"



Node::Node()
{
}

Node::~Node()
{
	while (_outcoming_connections.size()) disconnect(_outcoming_connections.back());
	while (_incoming_connections.size()) disconnect(_incoming_connections.back());
}

const std::list<std::shared_ptr<Connection>> & Node::outcoming_connections() const { return _outcoming_connections; }

const std::list<std::shared_ptr<Connection>> & Node::incoming_connections() const { return _incoming_connections; }

typename std::list<std::shared_ptr<Connection>>::iterator Node::find_outcoming_connection(std::shared_ptr<Connection> connection)
{
	return std::find(_outcoming_connections.begin(), _outcoming_connections.end(), connection);
}

typename std::list<std::shared_ptr<Connection>>::iterator Node::find_incoming_connection(std::shared_ptr<Connection> connection)
{
	return std::find(_incoming_connections.begin(), _incoming_connections.end(), connection);
}

void Node::disconnect(std::shared_ptr<Connection> connection)
{
	connection->k_source->_outcoming_connections.erase(connection->k_source->find_outcoming_connection(connection));
	connection->k_target->_incoming_connections.erase(connection->k_target->find_incoming_connection(connection));
}

