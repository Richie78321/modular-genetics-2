#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <bitset>
#include <tuple>

int main()
{
	ModularGenetics::GeneticSequence<6> sequence_1(std::bitset<6>("111111"));
	ModularGenetics::GeneticSequence<6> sequence_2(std::bitset<6>("000000"));

	for (int i = 0; i < 100; i++)
	{
		std::tuple<ModularGenetics::GeneticSequence<6>, ModularGenetics::GeneticSequence<6>> crossover_product = ModularGenetics::GeneticSequence<6>::Crossover(i, sequence_1, sequence_2);
		std::cout << std::get<0>(crossover_product).getBitSet()->to_string() << std::endl;
		std::cout << std::get<1>(crossover_product).getBitSet()->to_string() << std::endl;
		std::cout << std::endl;
	}

	std::cin.get();
}
