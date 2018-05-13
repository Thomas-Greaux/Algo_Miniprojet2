#include "parser.h"

Graph Parser::parse(string filename) const
{
	int vertex = 0;
	int edge = 0;

	ifstream ifile;
	ifile.open(filename);
	ifile >> vertex;
	ifile >> edge;
	ifile.close();

	cout << "filename : " << filename << endl;
	
	Graph res(vertex, edge);
	return res;
}
