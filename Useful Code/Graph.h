#pragma once
#include <list>
#include <memory>


class Graph;
class GraphNode;
class GraphOneWayConnection;


class Graph : public std::list<std::shared_ptr<GraphNode>>
{
public:
	Graph();
	virtual ~Graph();
};



class GraphNode
{
public:
	std::list <std::shared_ptr<GraphOneWayConnection>> outputConnections;

	Graph * const ParentGraph;

	GraphNode(Graph * const parentGraph);
	virtual ~GraphNode();
};



class GraphOneWayConnection
{
public:
	std::shared_ptr<GraphNode> Target;

	GraphOneWayConnection(std::shared_ptr<GraphNode> target);
	virtual ~GraphOneWayConnection();
};

