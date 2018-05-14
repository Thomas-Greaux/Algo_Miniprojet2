#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <vector>
using namespace std;

class Graph
{
	public:
		Graph(int vertex, int edge);
		int get_nb_vertex() const;
		int get_nb_edge() const;
		void add_edge(int v1, int v2);
		void print() const;
		void contract(int v1, int v2);
		vector<int> get_aleat_vertice() const;
		int get_weight_at_the_end() const;
        int get_nb_contractions() const;

	private:
		int nb_vertex;
		int nb_edge;
        int nb_contractions = 0;
		vector<vector<int>> matrix_adj;
};

#endif
