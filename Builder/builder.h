//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "stack.h"
#include "graph.h"
#include "graph_2.h"

class Builder
{
public:
	Builder(const char *fname_);//fname=fname_
	void loadInformation(Graph&);//������ ���������� � ����� �� ����������

private:
	int n;
	std::ifstream file;
	const char *fname;
	bool GetLine(std::string&);//�� ������� ������� ������
	bool openFile();//�������� �����
	void closeFile();//��������
	bool footerAnalysis(std::string&);//�������� footer

	bool isHeader(std::string);//�� he�der
	bool isFooter(std::string);//�� footer
	bool isEmptyLine(std::string);//�� ������� �����

	class Lexer
	{
	public:
		Lexer();
		~Lexer() = default;
		std::string init(const std::string& s_);//s=s_; pos=0
		bool get(std::string&, const char&);//�������� ����� �� ����������, �������� ������������
		std::string getRes()const;//������� ����� res
		bool eol()const;//pos>=s.size()
	private:
		std::string s;
		std::string res;
		static const char delim = ';';
		std::basic_string<char>::size_type pos = 0;
	};
};