#include <iostream>
#include "graph.h"
#include "parser.h"
#include "generator.h"

using namespace std;

int main()
{
	string filename = "./exemples/exemple1.txt";
	cout << "Parsing de l'exemple : " << endl;
	Parser parser;
	Graph graph = parser.parse(filename);
	graph.print();

	cout << "Generation de 4 exemples..." << endl;
	Generator generator;
	for(int i = 0; i < 4; i++)
	{
		generator.generate_exemple(0.2);
	}
	return 0;
}
