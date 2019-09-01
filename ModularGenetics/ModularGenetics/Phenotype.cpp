#include "stdafx.h"
#include "Phenotype.h"
#include <iterator>
#include <vector>
#include <stdexcept>
#include "GeneticSequence.h"

using namespace ModularGenetics;

Phenotype::Phenotype(int required_sequences, int required_length) : required_sequences(required_sequences), required_length(required_length)
{
}

void ModularGenetics::Phenotype::SetGenome(const std::vector<const GeneticSequence*>& genome, std::vector<const GeneticSequence*>::const_iterator first_sequence)
{
	//Ensure valid value
	if (std::distance(genome.cend(), first_sequence + this->required_sequences) < 0)
		throw std::invalid_argument("The size of the genome does not support this phenotype's sequence requirement.");

	std::vector<const GeneticSequence*>::const_iterator last_sequence = first_sequence + required_sequences;

	std::for_each(first_sequence, last_sequence, [this](const GeneticSequence* element)
	{
		if ((*element).sequence_length != this->required_length)
			throw std::invalid_argument("Not all genetic sequences are the phenotype's required length.");
	});

	this->genetic_sequences = std::vector<const GeneticSequence*>(first_sequence, last_sequence);
	genome_set = true;
}

const std::vector<const GeneticSequence*>& ModularGenetics::Phenotype::get_genetic_sequences() const
{
	return this->genetic_sequences;
}
