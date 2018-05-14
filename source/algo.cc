#include <iostream>
#include "graph.h"
#include "parser.h"
#include "generator.h"

using namespace std;

Graph delete_edge(Graph graph){
	vector<int> tab = graph.get_aleat_vertice();
	graph.contract(tab[0],tab[1]);
	graph.print();
	return graph;
}

int classique(Graph graph){
	while(graph.get_nb_vertex() > 2){
		graph = delete_edge(graph);
	}
	return graph.get_weight_at_the_end();
}

int karger_stein(Graph graph){
	int vertex_max = graph.get_nb_edge()*(pow(2,-0.5));
	while(graph.get_nb_vertex() > vertex_max){
		graph = delete_edge(graph);
	}
	vector<int> tab;
	for(int i = 0; i < 2; i++){
		int weight = classique(graph);
		tab.push_back(weight);
	}
	if(tab[0] < tab[1]){
		return tab[0];
	}
	else{
		return tab[1];
	}
}



int main()
{
	srand(time(NULL));
	string filename = "./exemples/exemple1.txt";
	cout << "Parsing de l'exemple : " << endl;
	Parser parser;
	Graph graph = parser.parse(filename);

	graph.print();
	graph.contract(1, 3);
	
	cout << "Apres contraction de 1 et 3 :" << endl;
	graph.print();

	graph.get_aleat_vertice();

	int x = classique(graph);
	cout << "CLASSIQUE : " << x << endl;
	x = karger_stein(graph);
	cout << "KARGER : " << x << endl;

	
	

	/*cout << "Generation de 4 exemples..." << endl;
	Generator generator;
	for(int i = 0; i < 4; i++)
	{
		generator.generate_exemple(0.2);
	}*/
	return 0;
}


