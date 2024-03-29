#include "Individual.h"
#include "RandomNumbers.h"
#include <vector>

Individual::Individual(const int genotypeLength, const double initialDensity) : fitnessMem{-1}{
	//creating a random population
	genotype.reserve(genotypeLength);
	for (int i = 0; i < genotypeLength; i++) {
		genotype.push_back(RandomNumbers::getNextDouble() < initialDensity);
	}
}

Individual::Individual(std::vector<bool>&& genotype) : fitnessMem{-1}, genotype { std::move(genotype) }{}

double Individual::fitness(const KnapsackProblem& problem) {
	//check if fitness has already been calculated
	if (fitnessMem != -1) {
		return fitnessMem;
	}
	//saving fitness for later use
	fitnessMem = problem.genotypeScore(genotype);
	return fitnessMem;
}

std::vector<Individual> Individual::crossover(const Individual& other, const double crossProb) const{
	// if parants are the same individual or there is no crossing, we can return copies of parents
	if (RandomNumbers::getNextDouble() > crossProb || this == &other) {
		return { Individual(*this), Individual(other) };
	}

	//new vectors for genotypes after crossover
	std::vector<bool> genotype1;
	std::vector<bool> genotype2;
	genotype1.reserve(genotype.size());
	genotype2.reserve(genotype.size());

	//random cross point, there are n-1 possible positions
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


void Individual::mutate(const double mutProb) {
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

double Individual::getFitnessMem() {
	return fitnessMem;
}

