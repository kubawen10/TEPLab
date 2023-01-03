#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include <iostream>
#include <vector>

class Individual {
private:
	std::vector<bool> genotype;
	double fitnessMem;

public:
	Individual(int genotypeLength);
	Individual(const Individual& other);
	Individual(std::vector<bool>& genotype);

	double fitness(double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values);
	std::vector<Individual> crossover(Individual& other, double crossProb);
	void mutate(double mutProb);

	std::vector<bool> getGenotype();

	friend std::ostream& operator<<(std::ostream& out, const Individual& individual);
};
#endif