#include "KnapsackProblem.h"
#include "Exceptions.h"
#include <fstream>
#include <vector>
#include <iostream>

KnapsackProblem::KnapsackProblem(int numberOfItems, double knapsackCapacity, const std::vector<double>& weights, const std::vector<double>& values) {
	init(numberOfItems, knapsackCapacity, values, weights);
}

KnapsackProblem::KnapsackProblem(const std::string& pathToFile) {
	//file should be formatted as:
	//numberOfItems knapsackCapacity
	//valueOfItem_1 weightOfItem_1
	//...
	//valueOfItem_numberOfItems weightOfItem_numberOfItems
	std::ifstream inf(pathToFile);

	if (!inf.is_open())
		throw CouldNotOpenFileException(pathToFile);

	double numberOfItemsInBuff;
	double knapsackCapacityIn;
	if (!(inf >> numberOfItemsInBuff >> knapsackCapacityIn)) {
		throw FileParsingException(NUMBER_OR_CAPACITY_EXCEPTION_MSG);
	}
	int numberOfItemsIn = numberOfItemsInBuff;
	std::vector<double> valueIn;
	std::vector<double> weightIn;

	double a, b;
	while (inf >> a >> b) {
		valueIn.push_back(a);
		weightIn.push_back(b);
	}
	if (!inf.eof()) {
		throw FileParsingException(VALUES_OR_WEIGHTS_EXCEPTION_MSG);
	}
	inf.close();

	init(numberOfItemsIn, knapsackCapacityIn, valueIn, weightIn);
}

void KnapsackProblem::init(int numberOfItems, double knapsackCapacity, const std::vector<double>& values, const std::vector<double>& weights) {
	if (numberOfItems <= 0) 
		throw InvalidArgumentException(NUMBER_OF_ITEMS_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG);
	this->numberOfItems = numberOfItems;

	if (knapsackCapacity <= 0) 
		throw InvalidArgumentException(KNAPSACK_CAPACITY_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG);
	this->knapsackCapacity = knapsackCapacity;

	if (weights.size() != numberOfItems || values.size() != numberOfItems) 
		throw InvalidArgumentException(DIFFERENT_VECTOR_SIZE_EXCEPTION_MSG);

	for (int i = 0; i < numberOfItems; i++) {
		if (weights[i] <= 0 || values[i] <= 0) 
			throw InvalidArgumentException(ITEM_VALUE_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG);
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

void KnapsackProblem::printGenotype(const std::vector<bool>& genotype) {
	std::cout << "Genotype: ";
	for (int i = 0; i < genotype.size(); i++) {
		std::cout << genotype[i] << " ";
	}

	std::cout << "\t\tScore: " << genotypeScore(genotype) << "\n";
}