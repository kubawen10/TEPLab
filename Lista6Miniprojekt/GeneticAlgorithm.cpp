#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "RandomNumbers.h"
#include <vector>

GeneticAlgorithm::GeneticAlgorithm(int popSize, double popInitialDensity, double crossProb, double mutProb, int iterations)
	: bestFitness{-1}, popSize{popSize}, iterations{iterations}
{
	if (popSize <= 0) {
		this->popSize = 1;
	}
	
	this->popInitialDensity = cropTo01Range(popInitialDensity);
	this->crossProb = cropTo01Range(crossProb);
	this->mutProb = cropTo01Range(mutProb);

	if (iterations < 0) {
		this->iterations = 0;
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
const std::vector<bool>& GeneticAlgorithm::solve(const KnapsackProblem& knapsack) {
	initPopulation(knapsack.getNumberOfItems());

	for (int i = 0; i < iterations; i++) {
		evaluatePopulation(knapsack);
		crossPopulation();
		mutatePopulation();
	}

	//evaluation after last cross and mutation
	evaluatePopulation(knapsack);

	return getBestGenotype();
}

void GeneticAlgorithm::initPopulation(const int numberOfItems) {
	//clear in case GA is used multiple times
	population.clear();
	bestFitness = -1;

	population.reserve(popSize);
	for (int i = 0; i < popSize; i++) {
		population.push_back(Individual(numberOfItems, popInitialDensity));
	}
}

void GeneticAlgorithm::evaluatePopulation(const KnapsackProblem& knapsack) {
	for (int i = 0; i < popSize; i++) {
		double curFitness = population[i].fitness(knapsack);

		//saving the best genotype overall
		if (curFitness > bestFitness) {
			bestFitness = curFitness;
			bestGenotype = population[i].getGenotype();
		}
	}
}

void GeneticAlgorithm::crossPopulation() {
	std::vector<Individual> newPopulation;
	newPopulation.reserve(population.size());

	while (newPopulation.size() < population.size()) {
		const Individual& parent1 = findParent();
		const Individual& parent2 = findParent();

		std::vector<Individual> children = parent1.crossover(parent2, crossProb);

		// adding children to newPopulation, if there is only one place left: add only first child (used if popSize is odd)
		newPopulation.push_back(std::move(children[0]));
		if(newPopulation.size() < population.size()) newPopulation.push_back(std::move(children[1]));
	}

	population = std::move(newPopulation);
}

const Individual& GeneticAlgorithm::findParent() {
	int p1 = RandomNumbers::getNextInt(0, population.size() - 1);
	int p2 = RandomNumbers::getNextInt(0, population.size() - 1);

	//picked the same individual, no need to calculate fitness in this case
	if (p1 == p2) return population[p1];

	//choose parent with better fitness, fitness was calculated during evaluation
	return population[p1].getFitnessMem() > population[p2].getFitnessMem() ? population[p1] : population[p2];
}

void GeneticAlgorithm::mutatePopulation() {
	for (int i = 0; i < population.size(); i++) {
		population[i].mutate(mutProb);
	}
}

const std::vector<bool>& GeneticAlgorithm::getBestGenotype() {
	return bestGenotype;
}

