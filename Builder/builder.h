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
	void loadInformation(Graph&);//додаємо інформацію з файлу до контейнеру

private:
	int n;
	std::ifstream file;
	const char *fname;
	bool GetLine(std::string&);//чи вдалося виділити строку
	bool openFile();//відкриття файлу
	void closeFile();//закриття
	bool footerAnalysis(std::string&);//аналізуємо footer

	bool isHeader(std::string);//чи heаder
	bool isFooter(std::string);//чи footer
	bool isEmptyLine(std::string);//чи порожній рядок

	class Lexer
	{
	public:
		Lexer();
		~Lexer() = default;
		std::string init(const std::string& s_);//s=s_; pos=0
		bool get(std::string&, const char&);//виділення слова до роздільника, заданого користувачем
		std::string getRes()const;//повертає слово res
		bool eol()const;//pos>=s.size()
	private:
		std::string s;
		std::string res;
		static const char delim = ';';
		std::basic_string<char>::size_type pos = 0;
	};
};