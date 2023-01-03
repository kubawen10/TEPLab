#ifndef MY_RANDOM_H
#define MY_RANDOM_H

#include <random>

class MyRandom {
private:
	std::mt19937 mt;
	std::uniform_int_distribution<> intGenerator;
	std::uniform_real_distribution<> realGenerator;

public:
	MyRandom(double lower, double upper) : intGenerator(lower, upper), realGenerator(lower, upper)
	{
		std::random_device rd;
		mt.seed(rd());
	}
		
	int getNextInt() {
		return intGenerator(mt);
	}

	double getNextDouble() {
		return realGenerator(mt);
	}
};

#endif