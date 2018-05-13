#include "graph.h"

Graph::Graph(int vertex, int edge) : nb_vertex(vertex), nb_edge(edge) 
{
	for(int i = 0; i < vertex; i++)
	{
		matrix_adj.push_back(vector<int>(vertex));
	}
}

void Graph::add_edge(int v1, int v2)
{
	matrix_adj[v1][v2] = 1;
	matrix_adj[v2][v1] = 1;
}

int Graph::get_nb_vertex() const
{
	return nb_vertex;
}

int Graph::get_nb_edge() const
{
	return nb_edge;
}

void Graph::print() const
{
	cout << "vertex : " << nb_vertex << endl;
	cout << "edge : " << nb_edge << endl;
	for(int i = 0; i < nb_vertex; i++)
	{
		cout << "vertex " << i << " connected to : ";
		for(int j = 0; j < nb_vertex; j++)
		{
			if(matrix_adj[i][j] != 0)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
