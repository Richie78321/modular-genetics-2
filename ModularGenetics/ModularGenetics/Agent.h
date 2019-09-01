#pragma once
#include <vector>

namespace ModularGenetics
{
	class Phenotype;
	class GeneticSequence;

	class Agent
	{
	public:
		Agent(std::vector<Phenotype> phenotypes, std::vector<const GeneticSequence*> genome);
		Agent(std::vector<Phenotype> phenotypes);
		~Agent();

		const std::vector<const GeneticSequence*>& get_genome() const;
		const std::vector<Phenotype> phenotypes;

	private:
		std::vector<const GeneticSequence*> genome;
		void ApplyGenome();
	};
}

