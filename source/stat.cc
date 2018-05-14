#include <iostream>
#include "algorithms.h"
#include "parser.h"
#include "generator.h"
#include "graph.h"

using namespace std;

int main()
{
	cout << "hello from stat" << endl;

    Algorithms algorithms;
	Generator generator;
	Parser parser;
	Graph* graph = nullptr;

	for(int i = 0; i < 50; i++)
	{
		cout << "generating exemple #" << i << endl;
		generator.generate_exemple(0.2);
	}

	for(int i = 0; i < 50; i++)
	{
		graph = new Graph(parser.parse("./exemples/g_exemple" + to_string(i) + ".txt"));
		
        int x = algorithms.classique(*graph);
        cout << "CLASSIQUE : " << x << endl;
        x = algorithms.karger_stein(*graph);
        cout << "KARGER : " << x << endl;
        x = algorithms.karger_stein_persalized(*graph);
        cout << "KARGER PERSO : " << x << endl;
		
        delete graph;
		graph = nullptr;
	}
	return 0;
}
