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

public:
	KnapsackProblem() = default;
	void init(int numberOfItems, double knapsackCapacity, std::vector<double> weights, std::vector<double> values);
	void init(std::string pathToFile);
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
};

#endif