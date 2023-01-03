#ifndef KNAPSACK_PROBLEM_H
#define KNAPSACK_PROBLEM_H

#include <vector>

class KnapsackProblem {
private:
	int numberOfItems;
	double knapsackCapacity;
	std::vector<double> weights;
	std::vector<double> values;

public:
	//double solutionScore(const std::vector<bool> solution);

};

#endif