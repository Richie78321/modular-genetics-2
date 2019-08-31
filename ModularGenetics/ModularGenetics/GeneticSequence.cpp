#include "stdafx.h"
#include "GeneticSequence.h"
#include <string>
#include <boost\dynamic_bitset.hpp>
#include <stdexcept>
#include <tuple>

using namespace ModularGenetics;

std::tuple<GeneticSequence, GeneticSequence> GeneticSequence::Crossover(int num_crossovers, const GeneticSequence & sequence_1, const GeneticSequence & sequence_2)
{
	//Validate values
	if (num_crossovers < 1)
		throw std::invalid_argument("Must have one or more crossovers.");
	if (sequence_1.sequence_length != sequence_2.sequence_length)
		throw std::invalid_argument("Genetic sequences must be of equal length to crossover.");

	std::string child_1, child_2;
	boost::to_string(sequence_1.bit_set, child_1);
	boost::to_string(sequence_2.bit_set, child_2);

	for (int i = 0; i < num_crossovers; i++)
	{
		int crossover_index = 1 + (rand() % (sequence_1.sequence_length - 1));

		//Crossover w/ substrings
		std::string new_child_1 = child_1.substr(0, crossover_index) + child_2.substr(crossover_index, sequence_1.sequence_length - crossover_index);
		std::string new_child_2 = child_2.substr(0, crossover_index) + child_1.substr(crossover_index, sequence_1.sequence_length - crossover_index);

		//Apply crossover
		child_1 = new_child_1;
		child_2 = new_child_2;
	}

	return std::tuple<GeneticSequence, GeneticSequence>(GeneticSequence(child_1), GeneticSequence(child_2));
}

GeneticSequence::GeneticSequence(int sequence_length, bool init_random) : sequence_length(sequence_length)
{
	if (init_random)
	{
		//Generate random string
		std::string bit_string = "";
		for (int i = 0; i < sequence_length; i++)
		{
			bit_string += (rand() + 1) % 2 == 0 ? '0' : '1';
		}
		this->bit_set = boost::dynamic_bitset<>(bit_string);
	}
	else
	{
		//Generate sequence of 0's of defined length
		this->bit_set = boost::dynamic_bitset<>(sequence_length);
	}
}

GeneticSequence::GeneticSequence(boost::dynamic_bitset<> bit_set) : sequence_length(bit_set.size())
{
	this->bit_set = bit_set;
}

GeneticSequence::GeneticSequence(std::string bit_string) : sequence_length(bit_string.length())
{
	this->bit_set = boost::dynamic_bitset<>(bit_string);
}

const boost::dynamic_bitset<>& ModularGenetics::GeneticSequence::get_bit_set() const
{
	return this->bit_set;
}

