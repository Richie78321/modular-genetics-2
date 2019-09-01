#pragma once
#include <vector>

namespace ModularGenetics
{
	class GeneticSequence;

	class Phenotype
	{
	public:
		Phenotype(int required_sequences, int required_length);
		const int required_sequences;
		const int required_length;

		void SetGenome(const std::vector<const GeneticSequence*> &genome, std::vector<const GeneticSequence*>::const_iterator first_sequence);
	
		const std::vector<const GeneticSequence*>& get_genetic_sequences() const;	

	private:
		bool genome_set = false;
		std::vector<const GeneticSequence*> genetic_sequences;
	};
}

