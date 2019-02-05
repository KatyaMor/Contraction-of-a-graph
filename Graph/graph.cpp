//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#include "graph.h"

Vertex::Vertex(int title_) { title = title_; }

bool Vertex::isIsolated()const
{
	return connections.empty();
}

Vertex::operator bool()
{
	return connections.size() <= 2;
}

bool Vertex::findCon(const int& c)
{
	if (connections.find(c)) return 1;
	return 0;
}

bool Vertex::addConnection(const int& n)
{
	connections.push(n);
	return !isIsolated();
}

bool Vertex::deleteConnection(const int& n)
{
	if (connections.remove(n)) return 1;
	return 0;
}

bool Vertex::showConnectionsForContraction(int& title1, int& title2)
{
	if (bool())
	{
		if (connections.size() == 1)
		{
			title1 = connections.top();
			title2 = -1;
		}
		if (connections.size() == 2)
		{
			title1 = connections.top();
			connections.pop();
			title2 = connections.top();
		}
		return 1;
	}
	return 0;
}

int Vertex::getTitle()const
{
	return title;
}
