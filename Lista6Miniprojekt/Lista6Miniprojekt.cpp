#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void run(int popSize, double popDensity, double crossProb, double mutProb, int interations, std::string filePath);
void printVector(std::vector<bool> v, double score);

int main()
{
	run(20, 0.5, 0.6, 0.05, 100, "./instances_01_KP/low-dimensional/f1_l-d_kp_10_269");
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/low-dimensional/f10_l-d_kp_20_879");
	//run(150, 0.02, 0.8, 0.05, 10000, "./instances_01_KP/large_scale/knapPI_2_200_1000_1");
}

void run(int popSize, double popDensity, double crossProb, double mutProb, int interations, std::string filePath) {
	KnapsackProblem knapsack;
	try {
		knapsack.init(filePath);
	}
	catch (std::string e) {
		std::cerr << e;
		std::cerr << "\nTerminating the program.";
		exit(EXIT_FAILURE);
	}
	GeneticAlgorithm ga(popSize, popDensity, crossProb, mutProb, interations);
	ga.solve(knapsack);

	printVector(ga.getBestGenotype(), knapsack.genotypeScore(ga.getBestGenotype()));
}

void printVector(std::vector<bool> v, double score) {
	std::cout << "Solution: ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}

	std::cout << "\t\tScore: " << score << "\n";
}
