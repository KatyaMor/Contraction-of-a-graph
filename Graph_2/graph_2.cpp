//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#include "graph_2.h"
#include "graph.h"
#include "stack.h"
#include <string>

using namespace std;

Graph::Graph() { IsEmpty(); }

bool Graph::IsEmpty()
{
	if (GR.empty()) isEmpty = true;
	else isEmpty = false;
	return isEmpty;
}

bool Graph::IsTrivial()const
{
	if (GR.size() == 1) return 1;
	return 0;
}

void Graph::InfoIfIsTrivial(ostream& f)const
{
	if (IsTrivial()) f << "\nContraction graph is trivial\n";
}

std::string Graph::InfoIfIsTrivial()const
{

	if (IsTrivial())
	{
		std::string info = "\nContraction graph is trivial\n";
		return info;
	}
}

void Graph::contraction()
{
	if (!IsEmpty() && !IsTrivial())
	{
		int title1 = 0, title2 = 0, n = GR.size();
		for (Stack<Vertex>::Iterator i = GR.begin(); i <= n; ++i)
		{
			Vertex *v = new Vertex(i);
			if (i.operator*().showConnectionsForContraction(title1, title2))
			{
				Vertex *t1 = new Vertex(title1);
				if (title2 == -1)
				{
					GR.find(*t1).operator*().deleteConnection(*v);
				}
				else
				{
					Vertex *t2 = new Vertex(title2);
					GR.find(*t1).operator*().deleteConnection(*v);
					GR.find(*t1).operator*().addConnection(*t2);
					GR.find(*t2).operator*().deleteConnection(*v);
					GR.find(*t2).operator*().addConnection(*t1);
					delete t2;
				}
				GR.remove(*v);
				delete t1;
			}
			delete v;
		}
	}
}

Stack<Vertex>::Iterator Graph::findVertex(const Vertex& v)
{
	return GR.find(v);
}

void Graph::addVertex(const Vertex& v)
{
	GR.push(v);
}
