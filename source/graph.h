#ifndef _GRAPH_H_
#define _GRAPH_H_

class Graph
{
	public:
		Graph(int vertex, int edge);
		int get_nb_vertex() const;
		int get_nb_edge() const;

	private:
		int nb_vertex;
		int nb_edge;
};

#endif
