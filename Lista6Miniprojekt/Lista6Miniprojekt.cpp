#include "KnapsackProblem.h"
#include "GeneticAlgorithm.h"
#include "Exceptions.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

void run(int popSize, double popDensity, double crossProb, double mutProb, int interations, std::string filePath);
void testExceptions();
int main()
{
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/low-dimensional/1-20items.txt");
	//run(70, 0.5, 0.7, 0.1, 10000, "./instances_01_KP/low-dimensional/2-23items.txt");
	//run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/low-dimensional/3-20items.txt");
	
	//run(200, 0.1, 0.7, 0.08, 10000, "./instances_01_KP/large_scale/1-100items.txt");
	//run(150, 0.02, 0.8, 0.05, 10000, "./instances_01_KP/large_scale/2-1000items.txt");
	//run(150, 0.02, 0.8, 0.05, 10000, "./instances_01_KP/large_scale/3-10000items.txt");

	//run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/toEdit.txt");

	//testExceptions();

	return 0;
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
		std::cerr << "\nSkipping the problem.\n";
	}
}

void testExceptions() {
	//wrong path
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/low-dimensional/1-20itemss.txt");

	//empty file
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/empty.txt");

	//only first row
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/onlyFirstRow.txt");

	//wron first row
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/wrongFirstRow.txt");

	//wrong number of items
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/wrongNumberOfItems.txt");

	//wrongParameter
	run(20, 0.5, 0.6, 0.05, 1000, "./instances_01_KP/wrong/wrongParameter.txt");
}
