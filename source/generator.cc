#include "generator.h"

void Generator::generate_exemple(double proba) const
{
	static int num = 0;
	string filename = "./exemples/g_exemple" + to_string(num) + ".txt";
	ofstream ofile(filename);

	uniform_int_distribution<int> distribution_i(3, 11);
	uniform_real_distribution<double> distribution_r(0.0,1.0);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	default_random_engine generator(seed);

	int nb_vertex = distribution_i(generator);
	double draw = 0.0;
	vector<vector<int>> edges;
	int connected = 0;
	for(int i = 0; i < nb_vertex; i++)
	{
        connected = 0;
		for(int j = i+1; j < nb_vertex; j++)
		{
			draw = distribution_r(generator);
            
			if(draw < proba)
			{
				edges.push_back(vector<int> {i, j});
				connected = 1;
			}
		}
		if(!connected && i != 0) //We make sure each vertex is connected
		{
			int connector = distribution_i(generator) % i;
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
