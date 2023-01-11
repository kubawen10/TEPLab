#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "KnapsackProblem.h"
#include <vector>

class Individual {
private:
	std::vector<bool> genotype;
	double fitnessMem;

public:
	Individual(int genotypeLength, double initialDensity);
	Individual(const Individual& other);
	Individual(Individual&& other);
	Individual(std::vector<bool>&& genotype);

	double fitness(const KnapsackProblem& problem);
	std::vector<Individual> crossover(const Individual& other, double crossProb) const;
	void mutate(double mutProb);

	const std::vector<bool>& getGenotype();
	std::vector<bool> copyGenotype();
	double getFitnessMem();
};
#endif