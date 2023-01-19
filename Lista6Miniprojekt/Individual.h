#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "KnapsackProblem.h"
#include <vector>

class Individual {
private:
	std::vector<bool> genotype;
	double fitnessMem;

public:
	Individual(const int genotypeLength, const double initialDensity);
	Individual(std::vector<bool>&& genotype);
	Individual(const Individual& other) = default;
	Individual(Individual&& other) = default;
	~Individual() = default;
	Individual& operator=(const Individual& other) = default;
	Individual& operator=(Individual&& other) = default;

	double fitness(const KnapsackProblem& problem);
	std::vector<Individual> crossover(const Individual& other, const double crossProb) const;
	void mutate(const double mutProb);

	const std::vector<bool>& getGenotype();
	double getFitnessMem();
};
#endif