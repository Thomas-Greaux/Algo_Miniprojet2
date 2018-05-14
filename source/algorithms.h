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
		Graph delete_edge(Graph graph);
        int classique(Graph graph);
        vector<int> karger_stein_general(Graph graph, int edge_max, int number_of_iterations);
        int karger_stein(Graph graph);
        int karger_stein_persalized(Graph graph);
};

#endif
