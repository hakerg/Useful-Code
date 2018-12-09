#include "Graph.h"



Graph::Graph()
{
}


Graph::~Graph()
{
}




GraphNode::GraphNode(Graph * const parentGraph) : ParentGraph(parentGraph)
{
}


GraphNode::~GraphNode()
{
	for (std::shared_ptr<GraphNode>& otherNode : *ParentGraph)
	{
		auto connectionIt = otherNode->outputConnections.begin();
		while (connectionIt != otherNode->outputConnections.end())
		{
			std::shared_ptr<GraphOneWayConnection>& connection = *connectionIt;
			if (&*(connection->Target) == this)
			{
				auto connectionItToRemove = connectionIt;
				connectionIt++;
				otherNode->outputConnections.erase(connectionItToRemove);
			}
			else connectionIt++;
		}
	}
}


GraphOneWayConnection::GraphOneWayConnection(std::shared_ptr<GraphNode> target) : Target(target)
{
}

GraphOneWayConnection::~GraphOneWayConnection()
{
}
