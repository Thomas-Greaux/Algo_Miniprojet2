#include "graph.h"

Graph::Graph(int vertex, int edge) : nb_vertex(vertex), nb_edge(edge)
{
}

int Graph::get_nb_vertex() const
{
	return nb_vertex;
}

int Graph::get_nb_edge() const
{
	return nb_edge;
}
