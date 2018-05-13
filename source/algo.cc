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
        cout << "nb vertex : " << graph.get_nb_vertex() << endl << "nb edges : " << graph.get_nb_edge() << 
endl;
	return 0;
}
