#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <bitset>
#include <tuple>
#include <boost\dynamic_bitset.hpp>
#include <vector>
#include <iostream>

using namespace ModularGenetics;

int main()
{
	std::vector<Agent*> agents;
	for (int i = 0; i < 100; i++)
	{
		std::vector<Phenotype> phenotypes;
		phenotypes.push_back(Phenotype(100, 10));
		phenotypes.push_back(Phenotype(20, 20));
		agents.push_back(new Agent(phenotypes));
	}

	std::cin.get();

	std::for_each(agents.begin(), agents.end(), [](Agent* element)
	{
		delete element;
	});

	agents.clear();

	std::cin.get();
}
