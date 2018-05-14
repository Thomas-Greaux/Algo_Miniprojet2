#include <iostream>
#include "algorithms.h"
#include "parser.h"
#include "generator.h"
#include "graph.h"

using namespace std;

int min (int x, int y, int z) {
	if(x < y){
		return x<z?x:z;
	}
	else{
		return y<z?y:z;
	}
}


int main()
{
	

    Algorithms algorithms;
	Generator generator;
	Parser parser;
	Graph* graph = nullptr;
	
	int classique = 0;
	int karger = 0;
	int karger_persalized = 0;

	for(int i = 0; i < 5; i++)
	{
		cout << "generating exemple #" << i << endl;
		generator.generate_exemple(0.2);
	
		graph = new Graph(parser.parse("./exemples/g_exemple" + to_string(i) + ".txt"));
		int minimum = graph->get_nb_vertex();
		int nb_min_classique = 0;
		int nb_min_karger_stein = 0;
		int nb_min_karger_stein_persalized = 0;

		for(int j = 0; j < 100; j++){
    	    int x = algorithms.classique(*graph);
    	    int y = algorithms.karger_stein(*graph);
    	    int z = algorithms.karger_stein_persalized(*graph);
			if(minimum > min(x, y, z)){
				minimum = min(x, y, z);
				nb_min_classique = 0;
				nb_min_karger_stein = 0;
				nb_min_karger_stein_persalized = 0;
			}
			if(minimum == x) nb_min_classique++;
			if(minimum == y) nb_min_karger_stein++;
			if(minimum == z) nb_min_karger_stein_persalized++;
		
			/*
    	    delete graph;
			graph = nullptr;*/
		}
		cout << "La coupe minimum est de : " << minimum << endl;
		cout << "CLASSIQUE : " << nb_min_classique << "/100" << endl;
		cout << "KARGER : " << nb_min_karger_stein << "/100" << endl;
		cout << "KARGER PERSO : " << nb_min_karger_stein_persalized << "/100" << endl;

		classique += nb_min_classique;
		karger += nb_min_karger_stein;
		karger_persalized += nb_min_karger_stein_persalized;

	}
	
	if(karger_persalized >= karger){
		if(karger >= classique) {
			cout << "Karger perso (" << karger_persalized << ") > Karger (" << karger << ") > Classique (" << classique << ")" << endl;
		}
		else if(classique > karger_persalized){
			cout << "> Classique (" << classique << ") Karger perso (" << karger_persalized << ") > Karger (" << karger << ")" << endl;
		}
		else {
			cout << "Karger perso (" << karger_persalized << ") > Classique (" << classique << ") > Karger (" << karger << ")" << endl;
		}
	}
	else{
		if (karger_persalized >= classique) {
			cout << "Karger (" << karger << ") > Karger perso (" << karger_persalized << ") > Classique (" << classique << ")" << endl; 
		}
		else if(classique > karger){ 
			cout << "> Classique (" << classique << ") > Karger (" << karger << ") Karger perso (" << karger_persalized << ") " << endl;
		}
		else {
			cout << "Karger (" << karger << ") > Classique (" << classique << ") > Karger perso (" << karger_persalized << ")" << endl;
		}
	}
	

	return 0;
}
