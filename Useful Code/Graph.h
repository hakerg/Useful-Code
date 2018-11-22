#pragma once
#include <list>
#include <memory>
#include "GraphNode.h"

class Graph
{
public:

	std::list<std::shared_ptr<GraphNode>> Nodes;


	Graph();
	~Graph();
};

