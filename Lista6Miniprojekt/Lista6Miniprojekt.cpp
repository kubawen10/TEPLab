#include "GeneticAlgorithm.h"
#include "Individual.h"
#include "MyRandom.h"
#include <iostream>
#include <vector>
#include <fstream>

int main()
{
	double cap = 269;
	int num = 10;

	std::vector<double> w{95, 4, 60, 32, 23, 72, 80, 62, 65, 46};
	std::vector<double> v{55, 10, 47, 5, 4, 50, 8, 61, 85, 87};

	GeneticAlgorithm ga(num, cap, w, v);

	ga.solve(15, 0.1, 0.05, 100000);
	//std::cout << ga.getBest();
}


// W - pojemnosc plecaka
// wi - objetosc przedmiotu i
// vi - wartosc  przedmiotu i
// xi - 1 gdy chcemy brac, 0 gdy nie
// V - wartosc obecnych przedmiotow


//file reading dziala

//std::ifstream inf{ "instances_01_KP/large_scale-optimum/knapPI_1_100_1000_1" };
//
//if (!inf) {
//    std::cout << "error";
//    return 1;
//}
//
//while (inf) {
//    std::string str;
//    inf >> str;
//    std::cout << str << "\n";
//}