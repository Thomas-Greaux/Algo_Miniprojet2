#include <iostream>
#include "arrete.h"
#include "graph.h"

using namespace std;

int main()
{
	Arrete arrete(1,2);
	arrete.getSommet1();
	Graph graph(4, 3);
        cout << "nb vertex : " << graph.get_nb_vertex() << endl << "nb edges : " << graph.get_nb_edge() << 
endl;
	return 0;
}
