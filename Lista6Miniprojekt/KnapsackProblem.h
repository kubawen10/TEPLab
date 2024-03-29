#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include <vector>
#include <string>

class KnapsackProblem {
private:
	int numberOfItems;
	double knapsackCapacity;
	std::vector<double> weights;
	std::vector<double> values;

	void init(int numberOfItems, double knapsackCapacity, const std::vector<double>& weights, const std::vector<double>& values);
	
	const std::string NUMBER_OR_CAPACITY_EXCEPTION_MSG = "Could not read number of items and/or knapsack capacity. The first row should be of format: 'numberOfItems knapsackCapacity'";
	const std::string VALUES_OR_WEIGHTS_EXCEPTION_MSG = "Could not read values and/or weights. There should be numberOfItems rows of format: 'value weight'";
	const std::string NUMBER_OF_ITEMS_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG = "Number of items should be greater than 0!";
	const std::string KNAPSACK_CAPACITY_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG = "Knapsack Capacity should be greater than 0!";
	const std::string DIFFERENT_VECTOR_SIZE_EXCEPTION_MSG = "Vector's size is different than the number of items!";
	const std::string ITEM_VALUE_LESS_OR_EQUAL_THAN_0_EXCEPTION_MSG = "Item's values and weights should be greater than 0!";

public:
	KnapsackProblem(int numberOfItems, double knapsackCapacity, const std::vector<double>& weights, const std::vector<double>& values);
	KnapsackProblem(const std::string& pathToFile);
	KnapsackProblem(const KnapsackProblem& other) = default;
	KnapsackProblem(KnapsackProblem&& other) = default;
	~KnapsackProblem() = default;
	KnapsackProblem& operator=(const KnapsackProblem& other) = default;
	KnapsackProblem& operator=(KnapsackProblem&& other) = default;
	
	double genotypeScore(const std::vector<bool>& genotype) const;

	int getNumberOfItems() const {
		return numberOfItems;
	}

	double getKnapsackCapacity() const {
		return knapsackCapacity;
	}

	const std::vector<double>& getWeights() const{
		return weights;
	}

	const std::vector<double>& getValues() const{
		return values;
	}

	void printGenotype(const std::vector<bool>& genotype);
};

#endif