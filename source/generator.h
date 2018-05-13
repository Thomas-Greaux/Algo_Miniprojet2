#ifndef _GENERATOR_H_
#define _GENERATOR_H_

#include <iostream>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;

class Generator
{
	private:
	public:
		Generator() = default;
		void generate_exemple(double proba) const;
};

#endif
