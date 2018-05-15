#include <iostream>
#include "graph.h"
#include "parser.h"
#include "generator.h"
#include "algorithms.h"

using namespace std;

int main()
{
	srand(time(NULL));
	string filename = "./exemples/g_exemple0.txt";
	cout << "Parsing de l'exemple : " << endl;
	Algorithms algorithms;
    	Parser parser;
	Graph graph = parser.parse(filename);

	graph.print();


	vector<int> x = algorithms.classique(graph);
	cout << "CLASSIQUE : " << x[0] << endl;
	x = algorithms.karger_stein(graph);
	cout << "KARGER : " << x[0] << endl;
	x = algorithms.karger_stein_persalized(graph);
	cout << "KARGER PERSO : " << x[0] << endl;

	return 0;
}


