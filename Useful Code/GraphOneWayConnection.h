#pragma once

class GraphOneWayConnection
{
public:
	void* Target;

	GraphOneWayConnection(void* target);
	~GraphOneWayConnection();
};

