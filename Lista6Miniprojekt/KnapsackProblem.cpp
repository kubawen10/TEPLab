#include "KnapsackProblem.h"
#include <fstream>
#include <vector>

KnapsackProblem::KnapsackProblem(int numberOfItems, double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values) {
	init(numberOfItems, knapsackCapacity, weights, values);
}

KnapsackProblem::KnapsackProblem(std::string pathToFile) {
	std::ifstream inf(pathToFile);

	if (!inf.is_open())
		throw std::string("Couldn't open file!");

	int numberOfItemsIn = 0;
	double knapsackCapacityIn = 0;
	std::vector<double> valueIn;
	std::vector<double> weightIn;

	double a, b;
	bool firstLine = true;
	while (inf >> a >> b) {
		if (firstLine) {
			numberOfItemsIn = a;
			knapsackCapacityIn = b;
			firstLine = false;
		}
		else {
			valueIn.push_back(a);
			weightIn.push_back(b);
		}
	}
	inf.close();

	init(numberOfItemsIn, knapsackCapacityIn, weightIn, valueIn);
}

void KnapsackProblem::init(int numberOfItems, double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values) {
	if (numberOfItems <= 0) 
		throw std::string("Number of items should be greater than 0!");
	this->numberOfItems = numberOfItems;

	if (knapsackCapacity <= 0) 
		throw std::string("Knapsack Capacity should be greater than 0!");
	this->knapsackCapacity = knapsackCapacity;

	if (weights.size() != numberOfItems || values.size() != numberOfItems) 
		throw std::string("Vector's size is different than the number of items!");

	for (int i = 0; i < numberOfItems; i++) {
		if (weights[i] <= 0 || values[i] <= 0) 
			throw std::string("Vectors' values should be greater than 0!");
	}
	this->weights = weights;
	this->values = values;
}

double KnapsackProblem::genotypeScore(const std::vector<bool>& genotype) const {
	double totalValue = 0;
	double totalWeight = 0;

	for (int i = 0; i < genotype.size(); i++) {
		totalValue += genotype[i] * values[i];
		totalWeight += genotype[i] * weights[i];

		// fitness == 0 if weight of the objects is greater than knapsack capacity
		if (totalWeight > knapsackCapacity) {
			return 0;
		}
	}

	return totalValue;
}