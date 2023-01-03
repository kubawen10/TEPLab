#ifndef GENETIC_ALGORITHM_H
#define GENETIC_ALGORITHM_H

#include "MyRandom.h"
#include "Individual.h"
#include <vector>

class GeneticAlgorithm {
private:
	int numberOfItems;
	double knapsackCapacity;
	std::vector<double> weights;
	std::vector<double> values;
	bool debug = true;
	
	std::vector<Individual> population;

	void initPopulation(int popSize);
	void crossPopulation(double crossProb);
	void mutatePopulation(double mutProb);

	Individual& findParent();

public:
	GeneticAlgorithm(int numberOfItems, double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values);
	void solve(int popSize, double crossProb, double mutProb, int iterations);
	Individual& getBest();

};

#endif