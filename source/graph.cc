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
				cout << j << "(" << matrix_adj[i][j] << ") ";
			}
		}
		cout << endl;
	}
}

vector<int> Graph::get_aleat_vertice() const
{
	srand(time(NULL));
	int v1;
	int v2;

	do
	{
		v1 = rand()%nb_vertex;
		v2 = rand()%nb_vertex; 
	} while(v1 == v2); //make sure we don't contract the same vertex
	cout << "Contracting " << v1 << " and " << v2 << endl; 
	

	vector<int> tableau;
	tableau.push_back(v1);
	tableau.push_back(v2);
	return tableau;
}

void Graph::contract(int v1, int v2)
{
	if(v1 == v2) return;
	for(int i = 0; i < nb_vertex; i++)
	{
		matrix_adj[v1][i] += matrix_adj[v2][i];
		matrix_adj[i][v1] = matrix_adj[v1][i];
	}

	//Deletions
	for(int i = 0; i < nb_vertex; i++)
	{
		matrix_adj[i].erase(matrix_adj[i].begin()+v2);
	}
	matrix_adj.erase(matrix_adj.begin()+v2);
	nb_vertex--;

	for(int i =0; i < nb_vertex; i++)
	{
		if(matrix_adj[i][i] != 0)
		{
			nb_edge -= matrix_adj[i][i];
			matrix_adj[i][i] = 0;
		}
	}
}
