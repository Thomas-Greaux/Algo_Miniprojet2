#include <iostream>
#include "arrete.h"
#include "graph.h"
#include "parser.h"

using namespace std;

int main()
{
	Arrete arrete(1,2);
	arrete.getSommet1();
	string filename = "./exemples/exemple1.txt";
	Parser parser;
	Graph graph = parser.parse(filename);
	graph.print();
	return 0;
}
