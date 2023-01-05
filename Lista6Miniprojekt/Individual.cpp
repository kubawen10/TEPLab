#include "Individual.h"
#include "RandomNumbers.h"
//#include <iostream>
#include <vector>

Individual::Individual(int genotypeLength, double initialDensity) : fitnessMem{-1}
{
	//creating a random population
	genotype.reserve(genotypeLength);
	for (int i = 0; i < genotypeLength; i++) {
		genotype.push_back(RandomNumbers::getNextDouble() < initialDensity);
	}
}

Individual::Individual(const Individual& other): fitnessMem{ other.fitnessMem }, genotype{ other.genotype }{}

Individual::Individual(Individual&& other) : fitnessMem{ other.fitnessMem }, genotype{ std::move(other.genotype) }{}

Individual::Individual(std::vector<bool>&& genotype) : fitnessMem{-1}, genotype { std::move(genotype) }{}

double Individual::fitness(double knapsackCapacity, const std::vector<double>& weights, const std::vector<double>& values) {
	//check if fitness has already been calculated
	if (fitnessMem != -1) {
		return fitnessMem;
	}

	double totalValue = 0;
	double totalWeight = 0;

	for (int i = 0; i < genotype.size(); i++) {
		totalValue += genotype[i] * values[i];
		totalWeight += genotype[i] * weights[i];

		// fitness == 0 if weight of the objects is greater than knapsack capacity
		if (totalWeight > knapsackCapacity) {
			fitnessMem = 0;
			return 0;
		}
	}

	fitnessMem = totalValue;
	return totalValue;
}

std::vector<Individual> Individual::crossover(const Individual& other, double crossProb) const{
	// if parants are the same individual or there is no crossing, we can return copies of parents
	if (RandomNumbers::getNextDouble() > crossProb || this == &other) {
		return { Individual(*this), Individual(other) };
	}

	//new vectors for genotypes after crossover
	std::vector<bool> genotype1;
	std::vector<bool> genotype2;
	genotype1.reserve(genotype.size());
	genotype2.reserve(genotype.size());

	//get random cross point, there are n-1 possible positions
	int crossPoint = RandomNumbers::getNextInt(1, genotype.size() - 1);

	//first part of the genotype remains the same for each parent, second is taken from the other parent
	for (int i = 0; i < crossPoint; i++) {
		genotype1.push_back(genotype[i]);
		genotype2.push_back(other.genotype[i]);
	}
	for (int i = crossPoint; i < genotype.size(); i++) {
		genotype1.push_back(other.genotype[i]);
		genotype2.push_back(genotype[i]);
	}

	return { Individual(std::move(genotype1)), Individual(std::move(genotype2)) };
}


void Individual::mutate(double mutProb) {
	for (int i = 0; i < genotype.size(); i++) {
		if (RandomNumbers::getNextDouble() < mutProb) {
			genotype[i] = !genotype[i];
			fitnessMem = -1;
		}
	}
}

const std::vector<bool>& Individual::getGenotype() {
	return genotype;
}

std::vector<bool> Individual::copyGenotype() {
	return genotype;
}

double Individual::getFitnessMem() {
	return fitnessMem;
}

