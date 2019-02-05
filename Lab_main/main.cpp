//////////////////////////////
//Created by Katya Morgunova//
//////////////////////////////

#include <string>
#include  <iostream>
#include "builder.h"
#include "copyright.h"
#include "stack.h"
#include "graph_2.h"

using namespace std;
using std::string;

int main()
{
	information();//copyright
	const char *nameoffile = "lab4.txt";
	Graph GR;
	Builder *build = new Builder(nameoffile);
	(*build).loadInformation(GR);
	GR.contraction();

	system("pause");
	return 0;
}