#include "generator.h"

void Generator::generate_exemple(double proba) const
{
	static int num = 0;
	string filename = "./exemples/g_exemple" + to_string(num) + ".txt";
	ofstream ofile(filename);

	uniform_int_distribution<int> distribution_i(0, 9);
	uniform_real_distribution<double> distribution_r(0.0,1.0);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);

	int nb_vertex = distribution_i(generator);
	double draw = 0.0;
	vector<vector<int>> edges;
	int connected = 0;
	for(int i = 0; i < nb_vertex; i++)
	{
		for(int j = i+1; j < nb_vertex; j++)
		{
			connected = 0;
			draw = distribution_r(generator);
			if(draw < proba)
			{
				edges.push_back(vector<int> {i, j});
				connected = 1;
			}
		}
		if(!connected) //We make sure each vertex is connected
		{
			int connector = 0;
			do
			{
				connector = distribution_i(generator);
			} while(connector >= nb_vertex || connector == i);
			edges.push_back(vector<int> {i, connector});
		}
	}
	ofile << nb_vertex << " " << edges.size() << endl;
	for(int i = 0; i < edges.size(); i++)
	{
		ofile << edges[i][0] << " " << edges[i][1] << endl;
	}
	ofile.close();
	num++;
	
}