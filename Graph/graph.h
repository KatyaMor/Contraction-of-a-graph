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
	operator bool();//�� ������ ������� <=2
	bool addConnection(const int&);
	//���� ������ �������, ���� ������, �� ������
	bool showConnectionsForContraction(int&, int&);
	//���� ������ <=2, �� ������ �������, �� ����� � �����, ���� �� ������ 1, �� ����� ������ ���������� -1
	int getTitle()const;//������� �������
	bool isIsolated()const;//�������� �� ������������ �������
	bool findCon(const int&);//���� �������� ������� � ������� � �����
	bool deleteConnection(const int&);//������ ��������� ������ �������
private:
	Stack <Vertex> connections;//��������� ������� ������
	int title;
};
