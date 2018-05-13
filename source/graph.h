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

	private:
		int nb_vertex;
		int nb_edge;
		vector<vector<int>> matrix_adj;
};

#endif
