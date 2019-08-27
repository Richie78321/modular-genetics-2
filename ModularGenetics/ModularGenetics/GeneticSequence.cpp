#include "stdafx.h"
#include "GeneticSequence.h"
#include <string>
#include <boost\dynamic_bitset.hpp>

GeneticSequence::GeneticSequence(int sequence_length, bool init_random)
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
