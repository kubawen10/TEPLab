#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "Individual.h"
#include "MyRandom.h"
#include <vector>

class GeneticAlgorithm {
private:
	int numberOfItems;
	double knapsackCapacity;
	std::vector<double> weights;
	std::vector<double> values;
	std::vector<Individual> population;

	//solve helpers
	void initPopulation(int popSize);
	void crossPopulation(double crossProb);
	void mutatePopulation(double mutProb);
	Individual& findParent();

	//debug
	bool debug = true;
	void printPopulationDebug(); // calculates fitness inside
public:
	GeneticAlgorithm(int numberOfItems, double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values);
	void solve(int popSize, double crossProb, double mutProb, int iterations);
	//std::vector<bool> getBest();
	Individual getBest();
};

#endif