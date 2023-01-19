#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include "Exceptions.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void run(int popSize, double popDensity, double crossProb, double mutProb, int interations, std::string filePath);

int main()
{
	run(20, 0.5, 0.6, 0.05, 100, "./instances_01_KP/low-dimensional/f1_l-d_kp_10_269");
	//run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/low-dimensional/f10_l-d_kp_20_879");
	//run(150, 0.02, 0.8, 0.05, 10000, "./instances_01_KP/large_scale/knapPI_2_200_1000_1");
}

void run(int popSize, double popDensity, double crossProb, double mutProb, int interations, std::string filePath) {
	
	try {
		//creating problem and GA
		KnapsackProblem knapsack(filePath);
		GeneticAlgorithm ga(popSize, popDensity, crossProb, mutProb, interations);
		
		//solving the problem 
		ga.solve(knapsack);

		//printing the results
		std::cout << "Solution found: ";
		knapsack.printGenotype(ga.getBestGenotype());
	}
	catch (std::exception& e) {
		std::cerr << e.what();
		std::cerr << "\nTerminating the program.";
		exit(EXIT_FAILURE);
	}
}
