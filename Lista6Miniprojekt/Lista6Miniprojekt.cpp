#include <iostream>
#include "MyRandom.h"
#include "Individual.h"
#include <vector>
#include "GeneticAlgorithm.h"

int main()
{
	double cap = 5;
	int num = 4;

	std::vector<double> w{ 4,1,3,2 };
	std::vector<double> v{ 5,1,4,3 };

	GeneticAlgorithm ga(num, cap, w, v);

	ga.solve(4, 0.6, 0.1, 100);
}

// W - pojemnosc plecaka
// wi - objetosc przedmiotu i
// vi - wartosc  przedmiotu i
// xi - 1 gdy chcemy brac, 0 gdy nie
// V - wartosc obecnych przedmiotow
