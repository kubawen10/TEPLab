#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <vector>
#include <iostream>

class Individual {
private:
	std::vector<bool> genotype;
	double fitnessMem;

public:
	Individual(int genotypeLength);
	Individual(std::vector<bool>& genotype);

	double fitness(double knapsackCapacity, std::vector<double>& objectWeights, std::vector<double>& objectValues);

	std::vector<Individual> crossover(Individual& other, double crossoverProbability);

	void mutate(double mutationProbability);

	friend std::ostream& operator<<(std::ostream& out, const Individual& individual);
};
#endif