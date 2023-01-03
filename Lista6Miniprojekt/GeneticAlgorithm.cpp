#include "GeneticAlgorithm.h"
#include <vector>

GeneticAlgorithm::GeneticAlgorithm(int numOfItems, double knapsackCap, std::vector<double>& objectWeights, std::vector<double>& objectValues) 
	: numberOfItems{numOfItems}, knapsackCapacity{knapsackCap}, weights{objectWeights}, values{objectValues}
{}

void GeneticAlgorithm::solve(int popSize, double crossProb, double mutProb, int iterations) {
	initPopulation(popSize);
	if (debug) {
		std::cout << "----- INITIAL POPULATION: -----\n";
		printPopulationDebug();
		std::cout << "\n\n";
	}

	for (int i = 0; i < iterations; i++) {
		crossPopulation(crossProb);
		mutatePopulation(mutProb);
	}

	if (debug) {
		std::cout << "----- LAST POPULATION: -----\n";
		printPopulationDebug();
		std::cout << "\n\n";
	}
}

void GeneticAlgorithm::initPopulation(int popSize) {
	//clear in case GA is used multiple times
	population.clear();
	population.reserve(popSize);
	for (int i = 0; i < popSize; i++) {
		population.push_back(Individual(numberOfItems));
	}
}

void GeneticAlgorithm::crossPopulation(double crossProb) {
	std::vector<Individual> newPopulation;
	newPopulation.reserve(population.size());

	while (newPopulation.size() < population.size()) {
		Individual& parent1 = findParent();
		Individual& parent2 = findParent();

		//cross parents
		std::vector<Individual> children = parent1.crossover(parent2, crossProb);

		// add children to newPopulation, if there is only one place left: add only first child
		newPopulation.push_back(children[0]);
		if(newPopulation.size()<population.size()) newPopulation.push_back(children[1]);
	}

	population = newPopulation;
}

Individual& GeneticAlgorithm::findParent() {
	MyRandom random(0, population.size() - 1);

	//randomly pick two parents
	int p1 = random.getNextInt();
	int p2 = random.getNextInt();

	//check if picked the same individual, no need to calculate fitness in this case
	if (p1 == p2) return population[p1];

	Individual& parent1 = population[p1];
	Individual& parent2 = population[p2];

	//calculate parents' fitness
	double fitness1 = parent1.fitness(knapsackCapacity, weights, values);
	double fitness2 = parent2.fitness(knapsackCapacity, weights, values);

	//choose parent with better fitness
	return fitness1 > fitness2 ? parent1 : parent2;
}

void GeneticAlgorithm::mutatePopulation(double mutProb) {
	for (int i = 0; i < population.size(); i++) {
		population[i].mutate(mutProb);
	}
}
//std::vector<bool> GeneticAlgorithm::getBest() {
Individual GeneticAlgorithm::getBest() {
	double top = 0;
	int best = 0;

	for (int i = 0; i < population.size(); i++) {
		double fit = population[i].fitness(knapsackCapacity, weights, values);
		if (fit>top) {
			best = i;
			top = fit;
		}
	}

	//return population[best].getGenotype();
	return population[best];
}


//DEBUG 
void GeneticAlgorithm::printPopulationDebug() {
	for (int i = 0; i < population.size(); i++) {
		population[i].fitness(knapsackCapacity, weights, values);
		std::cout << i << ". " << population[i] << "\n";
	}
	
}



