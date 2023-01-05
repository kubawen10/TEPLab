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

	//solve helpers
	void initPopulation(int popSize);
	void evaluatePopulation(const KnapsackProblem& knapsack);
	void crossPopulation(double crossProb);
	void mutatePopulation(double mutProb);
	const Individual& findParent();

public:
	GeneticAlgorithm(int popSize, double popInitialDensity, double crossProb, double mutProb, int iterations);
	void solve(const KnapsackProblem& knapsack);
	std::vector<bool> getBestGenotype();
};

#endif