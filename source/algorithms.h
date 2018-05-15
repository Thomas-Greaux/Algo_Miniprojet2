#ifndef _ALGORITHMS_H_
#define _ALGORITHMS_H_

#include <math.h>
#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Algorithms
{
	public:
		Algorithms() = default;
		void delete_edge(Graph* graph);
        vector<int> classique(Graph graph);
        vector<int> karger_stein_general(Graph* graph, int edge_max, int number_of_iterations);
        vector<int> karger_stein(Graph graph);
        vector<int> karger_stein_persalized(Graph graph);
};

#endif
