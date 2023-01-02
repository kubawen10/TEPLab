#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

class Individual {
private:
	bool* genotype;
	int genotypeLength;

public:
	Individual(int genotypeLength);

	template<typename W, typename V>
	V fitness(W knapsackCapacity, W* objectWeights, V* objectValues);

	void crossover(Individual& other, double crossoverProbability);

	void mutation(double mutationProbability);
};

Individual::Individual(int genotypeLength) {
	this->genotypeLength = genotypeLength;
	
	genotype = new bool[genotypeLength];

}

template<typename W, typename V>
V Individual::fitness(W knapsackCapacity, W* objectWeights, V* objectValues) {
	V result{};


}

#endif