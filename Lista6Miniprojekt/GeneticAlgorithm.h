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

	//helper methods
	double cropTo01Range(double x);
	void initPopulation(const int numberOfItems);
	void evaluatePopulation(const KnapsackProblem& knapsack);
	void crossPopulation();
	const Individual& findParent();
	void mutatePopulation();

public:
	GeneticAlgorithm(int popSize, double popInitialDensity, double crossProb, double mutProb, int iterations);
	GeneticAlgorithm(const GeneticAlgorithm& other) = default;
	GeneticAlgorithm(GeneticAlgorithm&& other) = default;
	~GeneticAlgorithm() = default;
	GeneticAlgorithm& operator=(const GeneticAlgorithm& other) = default;
	GeneticAlgorithm& operator=(GeneticAlgorithm&& other) = default;


	const std::vector<bool>& solve(const KnapsackProblem& knapsack);
	const std::vector<bool>& getBestGenotype();
};

#endif