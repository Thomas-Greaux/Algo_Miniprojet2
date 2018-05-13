#ifndef _PARSER_H_
#define _PARSER_H_

#include "graph.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Parser
{
	public:
		Parser() = default;
		Graph parse(string filename) const;
};

#endif
