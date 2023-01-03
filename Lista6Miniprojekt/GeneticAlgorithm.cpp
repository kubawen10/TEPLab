#include "GeneticAlgorithm.h"
#include <vector>

GeneticAlgorithm::GeneticAlgorithm(int numOfItems, double knapsackCap, std::vector<double>& objectWeights, std::vector<double>& objectValues) 
	: numberOfItems{numOfItems}, knapsackCapacity{knapsackCap}, weights{objectWeights}, values{objectValues}
{}

void GeneticAlgorithm::solve(int popSize, double crossProb, double mutProb, int iterations) {
	initPopulation(popSize);

	for (int i = 0; i < iterations; i++) {
		crossPopulation(crossProb);
		mutatePopulation(mutProb);
	}
}

void GeneticAlgorithm::initPopulation(int popSize) {
	//clear in case GA is used multiple times
	population.clear();
	population.reserve(popSize);
	for (int i = 0; i < popSize; i++) {
		population.push_back(Individual(numberOfItems));
	}

	if (debug) {
		for (int i = 0; i < population.size(); i++) {
			std::cout << population[i] << "\n";
		}
	}
}

void GeneticAlgorithm::crossPopulation(double crossProb) {
	std::vector<Individual> newPopulation;
	newPopulation.reserve(population.size());

	while (newPopulation.size() < population.size()) {
		//find parents to cross
		Individual& parent1 = findParent();
		Individual& parent2 = findParent();

		//cross parents
		std::vector<Individual> children = parent1.crossover(parent2, crossProb);

		// add children to newPopulation, if there is only one place left: add only first child
		newPopulation.push_back(children[0]);
		if(newPopulation.size()<population.size()) newPopulation.push_back(children[1]);
	}
}

Individual& GeneticAlgorithm::findParent() {
	MyRandom random(0, population.size() - 1);

	//randomly pick two parents
	Individual& parent1 = population[random.getNextInt()];
	Individual& parent2 = population[random.getNextInt()];

	//calculate parents' fitness
	double fitness1 = parent1.fitness(knapsackCapacity, weights, values);
	double fitness2 = parent2.fitness(knapsackCapacity, weights, values);

	//choose parent with better fitness
	if (fitness1 > fitness2) {
		return parent1;
	}
	else {
		return parent2;
	}
}

void GeneticAlgorithm::mutatePopulation(double mutProb) {
	for (int i = 0; i < population.size(); i++) {
		population[i].mutate(mutProb);
	}
}

Individual& GeneticAlgorithm::getBest() {
	double top = 0;
	int best = 0;

	for (int i = 0; i < population.size(); i++) {
		double f = population[i].fitness(knapsackCapacity, weights, values);
		if (f>top) {
			best = i;
			top = f;
		}
	}

	return population[best];
}




