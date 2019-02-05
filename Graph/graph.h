//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#pragma once

#include <string>
#include "stack.h"

class Vertex//vertex with its connections
{
public:
	Vertex(int title_);//title=title_
	operator bool();//чи степінь вершини <=2
	bool addConnection(const int&);
	//додає суміжну вершину, якщо вийшло, то правда
	bool showConnectionsForContraction(int&, int&);
	//якщо степінь <=2, то показує вершини, які суміжні з даною, якщо її степінь 1, то другій суміжній присвоюємо -1
	int getTitle()const;//повертає вершину
	bool isIsolated()const;//перевірка на ізольованість вершини
	bool findCon(const int&);//шукає відповідну вершину в суміжних з даною
	bool deleteConnection(const int&);//відаляє конкретну суміжну вершину
private:
	Stack <Vertex> connections;//контейнер суміжних вершин
	int title;
};
