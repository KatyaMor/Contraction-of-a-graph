//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#pragma once

#include <string>
#include "graph.h"
#include "stack.h"

class Graph
{
protected:
	Stack<Vertex> GR;
	bool isEmpty;
	bool IsEmpty();//чи порожній граф
	bool IsTrivial()const;//чи тривіальний граф
	
public:
	Graph();
	void contraction();//стягування графа
	void InfoIfIsTrivial(ostream& )const;//вивід інформації, якщо граф тривіальний в файл
	std::string InfoIfIsTrivial()const;//вивід інформації, якщо графф тривіальний на консоль
	Stack<Vertex>::Iterator findVertex(const Vertex&);//шукаємо конкретну вершину в графі
	void addVertex(const Vertex&);//додаємо конкретну вершину до графа

};