#pragma once
#include <boost\dynamic_bitset.hpp>

namespace ModularGenetics
{
	class GeneticSequence
	{
	public:
		static std::tuple<GeneticSequence, GeneticSequence> Crossover(int num_crossovers, const GeneticSequence& sequence_1, const GeneticSequence& sequence_2);

		GeneticSequence(int sequence_length, bool init_random);
		GeneticSequence(boost::dynamic_bitset<> bit_set);
		GeneticSequence(std::string bit_string);

		const boost::dynamic_bitset<>& get_bit_set() const;

		const int sequence_length;

	private:
		boost::dynamic_bitset<> bit_set;
	};
}

