#ifndef RANDOM_NUMBERS_H
#define RANDOM_NUMBERS_H

#include <random>

class RandomNumbers {
public:
	RandomNumbers() = delete;

	//generates random integers in range [low, high]
	static int getNextInt(int low, int high) {
		static std::random_device rd;
		static std::mt19937 mt(rd());

		std::uniform_int_distribution<> intGenerator(low, high);
		return intGenerator(mt);
	}

	//generates random doubles in range [0, 1]
	static double getNextDouble() {
		static std::random_device rd;
		static std::mt19937 mt(rd());
		static std::uniform_real_distribution<> realGenerator(0, 1);

		return realGenerator(mt);
	}
};

#endif