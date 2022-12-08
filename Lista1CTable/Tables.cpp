#include <iostream>

#include "Tables.h"

//ex1
void v_alloc_table_fill_34(int iSize) {
	//size validation
	if (iSize < 0) {
		std::cerr << WRONG_TABLE_SIZE_MSG;
		return;
	}

	//table allocation
	int* table;
	table = new int[iSize];

	//table fill
	for (int i = 0; i < iSize; i++)
	{
		table[i] = FILL_TABLE_WITH;
	}

	//print table
	for (int i = 0; i < iSize; i++)
	{
		std::cout << table[i];
		char separator = (i < iSize - 1) ? ' ' : '\n';
		std::cout << separator;
	}

	//table dealocation, should I use [] ? msvc and learncpp suggested it but script didnt?
	delete[] table;
}

//ex2
bool b_alloc_table_2_dim(int*** piTable, int iSizeX, int iSizeY) {
	//size validation
	if (iSizeX < 0 || iSizeX < 0) {
		std::cerr << WRONG_TABLE_SIZE_MSG;
		return false;
	}

	if (*piTable == nullptr) {
		std::cerr << NULLPTR_PASSED_MSG;
	}

	//take value of piTable (double pointer) and allocate table of int pointers
	*piTable = new int* [iSizeX];

	for (int i = 0; i < iSizeX; i++) {
		//take value of piTable (double pointer) and then take i-th element and allocate table of ints
		(*piTable)[i] = new int[iSizeY];
	}

	return true;
}

//zadanie 3
bool b_dealloc_table_2_dim(int*** piTable, int iSizeX) {
	//size validation
	if (iSizeX < 0) {
		std::cerr << WRONG_TABLE_SIZE_MSG;
		return false;
	}

	if (*piTable == nullptr) {
		std::cerr << NULLPTR_PASSED_MSG;
	}

	//table dealocation
	for (int i = 0; i < iSizeX; i++) {
		delete (*piTable)[i];
	}
	delete[] * piTable;

	return true;
}