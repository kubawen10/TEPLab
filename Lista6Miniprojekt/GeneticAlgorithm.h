#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "KnapsackProblem.h"
#include "Individual.h"
#include <vector>

class GeneticAlgorithm {
private:
	int popSize;
	double popInitialDensity;
	double crossProb; 
	double mutProb;
	int iterations;
	std::vector<Individual> population;

	double bestFitness;
	std::vector<bool> bestGenotype;

	double cropTo01Range(double x);

	//solve helpers
	void initPopulation(const int& numberOfItems);
	void evaluatePopulation(const KnapsackProblem& knapsack);
	void crossPopulation();
	const Individual& findParent();
	void mutatePopulation();

public:
	GeneticAlgorithm(int popSize, double popInitialDensity, double crossProb, double mutProb, int iterations);
	void solve(const KnapsackProblem& knapsack);
	const std::vector<bool>& getBestGenotype();
};

#endif