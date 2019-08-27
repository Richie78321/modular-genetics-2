#pragma once
#include <boost\dynamic_bitset.hpp>

class GeneticSequence
{
public:
	GeneticSequence(int sequence_length, bool init_random);

private:
	boost::dynamic_bitset<> bit_set;
};

