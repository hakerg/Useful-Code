#pragma once
#include <vector>
#include <memory>
#include "GraphOneWayConnection.h"

class GraphNode
{
public:
	std::vector <std::shared_ptr<GraphOneWayConnection>> outputConnections;

	GraphNode();
	~GraphNode();
};

