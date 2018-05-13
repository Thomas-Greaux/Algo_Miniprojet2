#include "parser.h"

Graph Parser::parse(string filename) const
{
	int vertex = 0;
	int edge = 0;

	ifstream ifile;
	ifile.open(filename);
	ifile >> vertex;
	ifile >> edge;

	Graph res(vertex, edge);

	int v1, v2;
	while(ifile >> v1)
	{
		ifile >> v2;
		res.add_edge(v1, v2);
	}
	ifile.close();

	
	return res;
}
