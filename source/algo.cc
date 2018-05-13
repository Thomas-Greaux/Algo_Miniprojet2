#include <iostream>
#include "graph.h"
#include "parser.h"
#include "generator.h"

using namespace std;


void classique(Graph graph){
	while(graph.get_nb_vertex() > 2){
		vector<int> tab = graph.get_aleat_vertice();
		graph.contract(tab[0],tab[1] );
		graph.print();
	}
}

int main()
{
	string filename = "./exemples/exemple1.txt";
	cout << "Parsing de l'exemple : " << endl;
	Parser parser;
	Graph graph = parser.parse(filename);

	graph.print();
	graph.contract(1, 3);
	
	cout << "Apres contraction de 1 et 3 :" << endl;
	graph.print();

	graph.get_aleat_vertice();

	classique(graph);

	/*cout << "Generation de 4 exemples..." << endl;
	Generator generator;
	for(int i = 0; i < 4; i++)
	{
		generator.generate_exemple(0.2);
	}*/
	return 0;
}


