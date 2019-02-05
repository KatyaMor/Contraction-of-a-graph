//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#include "builder.h"
#include <iostream>

using namespace std;

static const char delim = ';';

Builder::Lexer::Lexer() : s("") {}

bool Builder::Lexer::eol()const
{
	return pos >= s.size();
}

std::string Builder::Lexer::init(const string& source)
{
	s = source;
	pos = 0;
	pos = s.find_first_not_of(delim, pos);
	return s;
}

bool Builder::Lexer::get(string& current, const char& del)
{
	init(current);
	current.erase();
	if (eol()) return 0;
	auto pos1 = s.find_first_of(delim, pos);
	current = s.substr(pos, pos1 - pos);
	res = current;
	pos = pos1 + 1;
	return 1;
}

string Builder::Lexer::getRes()const
{
	return res;
}

Builder::Builder(const char *nameoffile)
{
	fname = nameoffile;
}

bool Builder::GetLine(string& s)
{
	if (getline(file, s)) return 1;
	return 0;
}

bool Builder::openFile()
{
	file.open(fname);
	if (file.fail())
	{
		file.close();
		return 0;
	}
	return 1;
}

void Builder::closeFile()
{
	file.close();
}

bool Builder::isHeader(std::string s)
{
	bool tr = false;
	Lexer *lex = new Lexer;
	std::string h="header";
	if (GetLine(s))
	{
		s = (*lex).init(s);
		(*lex).get(s, ':');
		if ((*lex).getRes()==h) tr=true;
	}
	delete lex;
	return tr;
}

bool Builder::isFooter(std::string s)
{
	bool tr = false;
	Lexer *lex = new Lexer;;
	std::string f = "footer";
	while(GetLine(s))
	{
		s = (*lex).init(s);
		(*lex).get(s, ':');
		if ((*lex).getRes() == f) tr=true;
	}
	delete lex;
	return tr;
}

bool Builder::footerAnalysis(std::string& s)
{
	bool tr = false;
	Lexer *lex = new Lexer;
	if (isFooter(s))
	{
		while (GetLine(s))
		{
			s = (*lex).init(s);
			(*lex).get(s, ':');
			(*lex).get(s, ';');
			n = atoi((*lex).getRes().c_str());
		}
		tr = true;
	}
	delete lex;
	return tr;
}

bool Builder::isEmptyLine(std::string s)
{
	bool tr = false;
	Lexer *lex = new Lexer;
	if (GetLine(s))
	{
		s = (*lex).init(s);
		(*lex).get(s, ';');
		if ((*lex).getRes() == "") tr=true;
	}
	delete lex;
	return tr;
}



void Builder::loadInformation(Graph& GR)
{
	if (openFile())
	{
		std::string s = "";
		getline(file, s);
		Lexer *lex = new Lexer;
		s = (*lex).init(s);
		if (isHeader(s)) getline(file, s);
		while (!isFooter(s))
		{
			if (!isEmptyLine(s))
			{
				int t1, t2;
				(*lex).get(s, ';');
				(*lex).get(s, ';');
				t1 = atoi((*lex).getRes().c_str());
				Vertex *v1 = new Vertex(t1);
				if (!GR.findVertex(*v1)) GR.addVertex(*v1);
				(*lex).get(s, ';');
				t2 = atoi((*lex).getRes().c_str());
				Vertex *v2 = new Vertex(t2);
				if (!GR.findVertex(*v1).operator*().findCon(t2)) GR.findVertex(*v1).operator*().addConnection(t2);
				if (!GR.findVertex(*v2)) GR.addVertex(*v2);
				if (!GR.findVertex(*v2).operator*().findCon(t1)) GR.findVertex(*v2).operator*().addConnection(t1);
				delete v1;
				delete v2;
			}
			getline(file, s);
			s = (*lex).init(s);
		}
		closeFile();
	}
	cout << "Can not open this file\n";
}