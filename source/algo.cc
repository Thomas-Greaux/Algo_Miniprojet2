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

vector<int> karger_stein_general(Graph graph, int edge_max, int number_of_iterations){
	while(graph.get_nb_vertex() > edge_max){
		graph = delete_edge(graph);
	}
	vector<int> tab;
	for(int i = 0; i < number_of_iterations; i++){
		int weight = classique(graph);
		tab.push_back(weight);
	}
	return tab;
	
}

int karger_stein(Graph graph){
	int edge_max = graph.get_nb_edge()*(pow(2,-0.5));
	vector<int> tab = karger_stein_general(graph, edge_max, 2);
	if(tab[0] < tab[1]){
		return tab[0];
	}
	else{
		return tab[1];
	}
	
}

int karger_stein_persalized(Graph graph){
	int edge_max = graph.get_nb_edge()/(1.1);
	int nbr_of_iterations = 3;
	int tmp = graph.get_nb_vertex(); 
	vector<int> tab = karger_stein_general(graph, edge_max, nbr_of_iterations);
	for(int i = 0; i < nbr_of_iterations; i++){
		if(tab[i] < tmp){
			tmp = tab[i];
		}
	}
	return tmp;
	
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
	x = karger_stein_persalized(graph);
	cout << "KARGER PERSO : " << x << endl;
	
	

	/*cout << "Generation de 4 exemples..." << endl;
	Generator generator;
	for(int i = 0; i < 4; i++)
	{
		generator.generate_exemple(0.2);
	}*/
	return 0;
}


