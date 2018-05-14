#include <iostream>
#include "graph.h"
#include "parser.h"
#include "generator.h"
#include "algorithms.h"

using namespace std;

int main()
{
	srand(time(NULL));
	string filename = "./exemples/exemple1.txt";
	cout << "Parsing de l'exemple : " << endl;
	Algorithms algorithms;
    Parser parser;
	Graph graph = parser.parse(filename);

	graph.print();
	graph.contract(1, 3);
	
	cout << "Apres contraction de 1 et 3 :" << endl;
	graph.print();

	graph.get_aleat_vertice();

	int x = algorithms.classique(graph);
	cout << "CLASSIQUE : " << x << endl;
	x = algorithms.karger_stein(graph);
	cout << "KARGER : " << x << endl;
	x = algorithms.karger_stein_persalized(graph);
	cout << "KARGER PERSO : " << x << endl;

	return 0;
}


