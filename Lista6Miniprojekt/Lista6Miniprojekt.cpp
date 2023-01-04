#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "MyRandom.h"
#include "KnapsackProblem.h"
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void printVector(std::vector<bool> v, double score);

int main()
{
	KnapsackProblem k;
	try {
		//k.init("./instances_01_KP/low-dimensional/f1_l-d_kp_10_269");
		//k.init("./instances_01_KP/low-dimensional/f10_l-d_kp_20_879");
		k.init("./instances_01_KP/large_scale/knapPI_2_200_1000_1");
	}
	catch (std::string e) {
		std::cerr << e;
		std::cerr << "\nTerminating the program.";
		return EXIT_FAILURE;
	}
	GeneticAlgorithm ga(150, 0.02, 0.8, 0.05, 10000);
	ga.solve(k);

	printVector(ga.getBestGenotype(), k.genotypeScore(ga.getBestGenotype()));

	return EXIT_SUCCESS;
}

void printVector(std::vector<bool> v, double score) {
	std::cout << "Solution: ";
	for (int i = 0; i < v.size(); i++) {
		std::cout << v[i] << " ";
	}

	std::cout << "\t\tScore: " << score;
}
