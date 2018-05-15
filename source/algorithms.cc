#include <iostream>
#include "algorithms.h"

using namespace std;

Graph Algorithms::delete_edge(Graph* graph){
	vector<int> tab = graph->get_aleat_vertice();
	graph->contract(tab[0],tab[1]);
	return *graph;
}

//Classique algorithm
vector<int> Algorithms::classique(Graph graph){
	vector<int> solution_contractions;
	while(graph.get_nb_vertex() > 2){
		graph = delete_edge(&graph);
	}
	solution_contractions.push_back(graph.get_weight_at_the_end());
	solution_contractions.push_back(graph.get_nb_contractions());
	return solution_contractions;
}


vector<int> Algorithms::karger_stein_general(Graph* graph, int edge_max, int number_of_iterations){
	while(graph->get_nb_vertex() > edge_max){
		*graph = delete_edge(graph);
	}
	vector<int> tab;
	for(int i = 0; i < number_of_iterations; i++){
		vector<int> weight = classique(*graph);
		tab.push_back(weight[0]);
	}
	return tab;
	
}


//Karger-Stein algorithm
vector<int> Algorithms::karger_stein(Graph graph){
	vector<int> solution_contractions;
	int edge_max = graph.get_nb_edge()*(pow(2,-0.5));
	vector<int> tab = karger_stein_general(&graph, edge_max, 2);
	if(tab[0] < tab[1]){
		solution_contractions.push_back(tab[0]);
	}
	else{
		solution_contractions.push_back(tab[1]);
	}
	solution_contractions.push_back(graph.get_nb_contractions());
	return solution_contractions;
}

//Karger-Stein perso algorithm
vector<int> Algorithms::karger_stein_persalized(Graph graph){
	vector<int> solution_contractions;
	int edge_max = graph.get_nb_edge()/(1.1);
	int nbr_of_iterations = 3;
	int tmp = graph.get_nb_vertex(); 
	vector<int> tab = karger_stein_general(&graph, edge_max, nbr_of_iterations);
	for(int i = 0; i < nbr_of_iterations; i++){
		if(tab[i] < tmp){
			tmp = tab[i];
		}
	}
	solution_contractions.push_back(tmp);
	solution_contractions.push_back(graph.get_nb_contractions());
	return solution_contractions;
	
}


