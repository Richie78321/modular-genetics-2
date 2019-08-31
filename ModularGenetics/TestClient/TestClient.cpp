#include "pch.h"
#include <iostream>
#include "ModularGenetics.h"
#include <bitset>
#include <tuple>
#include <boost\dynamic_bitset.hpp>

using namespace ModularGenetics;

int main()
{
	GeneticSequence test_seq_1 = GeneticSequence("000000");
	GeneticSequence test_seq_2 = GeneticSequence("111111");

	srand((unsigned)std::time(NULL));
	std::tuple<GeneticSequence, GeneticSequence> child_seq = GeneticSequence::Crossover(2, test_seq_1, test_seq_2);

	std::string child_1, child_2;
	boost::to_string(std::get<0>(child_seq).get_bit_set(), child_1);
	boost::to_string(std::get<1>(child_seq).get_bit_set(), child_2);

	std::cout << child_1 << std::endl;
	std::cout << child_2 << std::endl;

	std::cin.get();
}
