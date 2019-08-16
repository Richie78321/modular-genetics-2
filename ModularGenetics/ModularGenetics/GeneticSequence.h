#pragma once
#include <bitset>
#include <string>

namespace ModularGenetics
{
	template<int T>
	class GeneticSequence
	{
	public:
		static std::tuple<GeneticSequence<T>, GeneticSequence<T>> Crossover(int num_crossover, GeneticSequence<T> const& p1, GeneticSequence<T> const& p2);
		static std::tuple<GeneticSequence<T>, GeneticSequence<T>> ContinuousCrossover(GeneticSequence<T> const& p1, GeneticSequence<T> const& p2);

		std::bitset<T> getRandom() const;

		GeneticSequence();
		GeneticSequence(bool init_random);
		GeneticSequence(std::bitset<T> bit_set);

		void mutate(double mutation_rate);

		std::bitset<T> const* getBitSet() const;

	private:
		std::bitset<T> bit_set;
	};

	template<int T>
	inline std::tuple<GeneticSequence<T>, GeneticSequence<T>> GeneticSequence<T>::Crossover(int num_crossover, GeneticSequence<T> const & p1, GeneticSequence<T> const & p2)
	{
		std::string c1_string = p1.bit_set.to_string();
		std::string c2_string = p2.bit_set.to_string();

		for (int i = 0; i < num_crossover; i++)
		{
			int crossover_point = 1 + (rand() % (T - 1));

			std::string new_c1_string = c1_string.substr(0, crossover_point) + c2_string.substr(crossover_point);
			std::string new_c2_string = c2_string.substr(0, crossover_point) + c1_string.substr(crossover_point);

			c1_string = new_c1_string;
			c2_string = new_c2_string;
		}

		return std::tuple<GeneticSequence<T>, GeneticSequence<T>>(GeneticSequence<T>(std::bitset<T>(c1_string)), GeneticSequence<T>(std::bitset<T>(c2_string)));
	}

	template<int T>
	inline std::tuple<GeneticSequence<T>, GeneticSequence<T>> GeneticSequence<T>::ContinuousCrossover(GeneticSequence<T> const & p1, GeneticSequence<T> const & p2)
	{
		std::string c1_string = "";
		std::string c2_string = "";
		std::string p1_string = p1.bit_set.to_string();
		std::string p2_string = p2.bit_set.to_string();

		for (int i = 0; i < T; i++)
		{
			if ((rand() + 1) % 2 == 0)
			{
				c1_string += p1_string.at(i);
				c2_string += p2_string.at(i);
			}
			else
			{
				c1_string += p2_string.at(i);
				c2_string += p1_string.at(i);
			}
		}

		return std::tuple<GeneticSequence<T>, GeneticSequence<T>>(GeneticSequence<T>(std::bitset<T>(c1_string)), GeneticSequence<T>(std::bitset<T>(c2_string)));
	}

	template<int T>
	inline std::bitset<T> GeneticSequence<T>::getRandom() const
	{
		std::string bit_string = "";
		for (int i = 0; i < T; i++)
		{
			bit_string += (rand() + 1) % 2 == 0 ? "0" : "1";
		}

		return std::bitset<T>(bit_string);
	}

	template<int T>
	inline GeneticSequence<T>::GeneticSequence()
	{
		this->bit_set = std::bitset<T>();
	}

	template<int T>
	inline GeneticSequence<T>::GeneticSequence(bool init_random)
	{
		if (init_random)
			this->bit_set = this->getRandom();
		else
			this->bit_set = std::bitset<T>();
	}

	template<int T>
	inline GeneticSequence<T>::GeneticSequence(std::bitset<T> bit_set)
	{
		this->bit_set = bit_set;
	}

	template<int T>
	inline void GeneticSequence<T>::mutate(double mutation_rate)
	{
		for (int i = 0; i < T; i++)
		{
			if (rand() / RAND_MAX <= mutation_rate)
				this->bit_set.flip(i);
		}
	}

	template<int T>
	inline std::bitset<T> const * GeneticSequence<T>::getBitSet() const
	{
		return &this->bit_set;
	}
}

