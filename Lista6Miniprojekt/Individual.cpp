#include "Individual.h"
#include "MyRandom.h"
#include <vector>
#include <iostream>

Individual::Individual(int genotypeLength) : fitnessMem{-1}
{
	MyRandom rnd(0, 1);
	genotype.reserve(genotypeLength);
	for (int i = 0; i < genotypeLength; i++) {
		genotype.push_back(rnd.getNextInt());
	}
}

Individual::Individual(std::vector<bool>& otherGenotype) : fitnessMem{-1}, genotype{otherGenotype}{}

double Individual::fitness(double knapsackCapacity, std::vector<double>& weights, std::vector<double>& values) {
	if (fitnessMem != -1) {
		return fitnessMem;
	}

	double totalValue = 0;
	double totalWeight = 0;

	for (int i = 0; i < genotype.size(); i++) {
		totalValue += genotype[i] * values[i];
		totalWeight += genotype[i] * weights[i];

		if (totalWeight > knapsackCapacity) return 0;
	}

	fitnessMem = totalValue;
	return totalValue;
}

std::vector<Individual> Individual::crossover(Individual& other, double crossoverProbability) {
	std::vector<bool> genotype1;
	std::vector<bool> genotype2;

	MyRandom probabilityRand(0, 1);
	if (probabilityRand.getNextDouble() < crossoverProbability) {
		
		MyRandom crossRand(1, genotype.size() - 1);
		int crossPoint = crossRand.getNextInt();
		genotype1.reserve(genotype.size());
		genotype2.reserve(genotype.size());

		for (int i = 0; i < crossPoint; i++) {
			genotype1.push_back(genotype[i]);
			genotype2.push_back(other.genotype[i]);
		}
		for (int i = crossPoint; i < genotype.size(); i++) {
			genotype1.push_back(other.genotype[i]);
			genotype2.push_back(genotype[i]);
		}
	}
	else {
		genotype1 = genotype;
		genotype2 = other.genotype;
	}

	return { Individual(genotype1), Individual(genotype2) };
}


void Individual::mutate(double mutationProbability) {
	MyRandom rnd(0, 1);

	for (int i = 0; i < genotype.size(); i++) {
		if (rnd.getNextDouble() < mutationProbability) {
			genotype[i] = -1 * genotype[i];
			fitnessMem = -1;
		}
	}
}

std::ostream& operator<<(std::ostream& out, const Individual& individual) {
	out << "Genotype: ";
	out << "[";
	for (int i = 0; i < individual.genotype.size(); i++) {
		out << individual.genotype[i];

		if (i == individual.genotype.size() - 1) {
			out << "]";
		}
		else {
			out << ", ";
		}
	}

	return out;
}

