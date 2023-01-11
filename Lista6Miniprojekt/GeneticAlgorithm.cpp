#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "RandomNumbers.h"
#include <vector>

GeneticAlgorithm::GeneticAlgorithm(int popSize, double popInitialDensity, double crossProb, double mutProb, int iterations)
	: bestFitness{-1}
{
	if (popSize <= 0) {
		popSize = 1;
	}
	else {
		this->popSize = popSize;
	}
	
	this->popInitialDensity = cropTo01Range(popInitialDensity);
	this->crossProb = cropTo01Range(crossProb);
	this->mutProb = cropTo01Range(mutProb);

	if (iterations < 0) {
		this->iterations = 0;
	}
	else {
		this->iterations = iterations;
	}
}

double GeneticAlgorithm::cropTo01Range(double x) {
	if (x < 0) {
		return 0;
	}
	else if (x > 1) {
		return 1;
	}
	else {
		return x;
	}
}

//main method of the algorithm
void GeneticAlgorithm::solve(const KnapsackProblem& knapsack) {
	initPopulation(knapsack.getNumberOfItems());

	for (int i = 0; i < iterations; i++) {
		evaluatePopulation(knapsack);
		crossPopulation(crossProb);
		mutatePopulation(mutProb);
	}

	//evaluation after last cross and mutation
	evaluatePopulation(knapsack);
}

void GeneticAlgorithm::initPopulation(int numberOfItems) {
	//clear in case GA is used multiple times
	population.clear();

	population.reserve(popSize);
	for (int i = 0; i < popSize; i++) {
		population.push_back(Individual(numberOfItems, popInitialDensity));
	}
}

void GeneticAlgorithm::evaluatePopulation(const KnapsackProblem& knapsack) {
	for (int i = 0; i < popSize; i++) {
		double curFitness = population[i].fitness(knapsack);

		if (curFitness > bestFitness) {
			bestFitness = curFitness;
			bestGenotype = population[i].copyGenotype();
		}
	}
}

void GeneticAlgorithm::crossPopulation(double crossProb) {
	std::vector<Individual> newPopulation;
	newPopulation.reserve(population.size());

	while (newPopulation.size() < population.size()) {
		const Individual& parent1 = findParent();
		const Individual& parent2 = findParent();

		//cross parents
		std::vector<Individual> children = std::move(parent1.crossover(parent2, crossProb));

		// add children to newPopulation, if there is only one place left: add only first child (when popSize is odd)
		newPopulation.push_back(std::move(children[0]));
		if(newPopulation.size() < population.size()) newPopulation.push_back(std::move(children[1]));
	}

	population = std::move(newPopulation);
}

const Individual& GeneticAlgorithm::findParent() {
	//randomly pick two parents
	int p1 = RandomNumbers::getNextInt(0, population.size() - 1);
	int p2 = RandomNumbers::getNextInt(0, population.size() - 1);

	//picked the same individual, no need to calculate fitness in this case
	if (p1 == p2) return population[p1];

	//choose parent with better fitness
	return population[p1].getFitnessMem() > population[p2].getFitnessMem() ? population[p1] : population[p2];
}

void GeneticAlgorithm::mutatePopulation(double mutProb) {
	for (int i = 0; i < population.size(); i++) {
		population[i].mutate(mutProb);
	}
}

std::vector<bool> GeneticAlgorithm::getBestGenotype() {
	return bestGenotype;
}

