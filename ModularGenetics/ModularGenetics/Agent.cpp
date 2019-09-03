#include "stdafx.h"
#include "Agent.h"
#include <vector>
#include "GeneticSequence.h"
#include <numeric>
#include "Phenotype.h"
#include <stdexcept>

using namespace ModularGenetics;

Agent::Agent(std::vector<Phenotype> phenotypes, std::vector<const GeneticSequence*> genome) : phenotypes(phenotypes)
{
	int genome_length_requirement = std::accumulate(phenotypes.begin(), phenotypes.end(), 0, [](int total, Phenotype phenotype) { return total + phenotype.required_sequences; });
	if (genome_length_requirement != genome.size())
		throw std::invalid_argument("Agent's genome does not match its required genome length.");

	this->genome = genome;
}

Agent::Agent(std::vector<Phenotype> phenotypes) : phenotypes(phenotypes)
{
	int genome_length_requirement = std::accumulate(phenotypes.begin(), phenotypes.end(), 0, [](int total, Phenotype phenotype) { return total + phenotype.required_sequences; });
	
	//Init genome randomly
	std::vector<const GeneticSequence*>* genome = &this->genome;
	std::for_each(phenotypes.begin(), phenotypes.end(), [genome](Phenotype element)
	{
		for (int i = element.required_sequences - 1; i >= 0; i--)
		{
			genome->push_back(new GeneticSequence(element.required_length, true));
		}
	});
}

Agent::~Agent()
{
	//Clear agent genome
	std::for_each(this->genome.begin(), this->genome.end(), [](const GeneticSequence* element)
	{
		delete element;
	});
}

const std::vector<const GeneticSequence*>& ModularGenetics::Agent::get_genome() const
{
	return this->genome;
}

void ModularGenetics::Agent::ApplyGenome()
{
	const std::vector<const GeneticSequence*> genome = this->get_genome();
	int phenotype_increment = 0;
	std::for_each(this->phenotypes.begin(), this->phenotypes.end(), [&genome, &phenotype_increment](Phenotype element) 
	{
		element.SetGenome(genome, genome.cbegin() + phenotype_increment);
		phenotype_increment += element.required_sequences;
	});
}
