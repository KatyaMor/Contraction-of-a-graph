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
	bool IsEmpty();//�� ������� ����
	bool IsTrivial()const;//�� ���������� ����
	
public:
	Graph();
	void contraction();//���������� �����
	void InfoIfIsTrivial(ostream& )const;//���� ����������, ���� ���� ���������� � ����
	std::string InfoIfIsTrivial()const;//���� ����������, ���� ����� ���������� �� �������
	Stack<Vertex>::Iterator findVertex(const Vertex&);//������ ��������� ������� � �����
	void addVertex(const Vertex&);//������ ��������� ������� �� �����

};