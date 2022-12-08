#include <iostream>
#include <cassert>

#include "CTable.h"

CTable::CTable() {
	sName = DEFAULT_NAME;
	std::cout << "bezp: '" << sName << "'\n";
	tableLength = DEFAULT_TABLE_LENGTH;
	table = new int[tableLength];
	modified = true;
}

CTable::CTable(std::string sName, int iTableLen) {
	assert(iTableLen >= 0 && "Table length cannot be less than 0!\n"); //cant put const value?
	this->sName = sName;
	std::cout << "parametr: '" << this->sName << "'\n";
	tableLength = iTableLen;
	table = new int[tableLength];
	modified = true;
}

CTable::CTable(const CTable& pcOther) {
	sName = pcOther.sName + "_copy";
	tableLength = pcOther.tableLength;
	table = pcOther.table;
	std::cout << "Kopiuj: '" << pcOther.sName << "'\n";
	modified = false;
}

CTable::~CTable() {
	std::cout << "Usuwam: '" << sName << "'\n";
	if (modified) {
		std::cout << "Usuwanie tablicy, slynny bug?\n";
		delete[] table;
	}
}

void CTable::vSetName(std::string sName) {
	this->sName = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (!modified) {
		copyTable();
		modified = true;
	}



	int smallerTableLength;
	if (tableLength >= iTableLen) {
		smallerTableLength = iTableLen;
	}
	else {
		smallerTableLength = tableLength;
	}

	tableLength = iTableLen;
	int* newTab;
	newTab = new int[tableLength];

	for (int i = 0; i < smallerTableLength; i++) {
		newTab[i] = table[i];
	}

	delete[] table;
	table = newTab;

	return true;
}

CTable* CTable::pcClone() {
	return new CTable(*this);
}

void CTable::printTable() {
	std::cout << sName << ": ";
	for (int i = 0; i < tableLength; i++) {
		std::cout << table[i] << " ";
	}
	std::cout << "\n";
}

void CTable::fill() {
	for (int i = 0; i < tableLength; i++) {
		table[i] = i;
	}
}

bool CTable::writeValue(int index, int value) {
	if (index < 0 || index >= tableLength) {
		std::cerr << "wrong index";
		return false;
	}


	if (!modified) {
		copyTable();
		modified = true;
	}

	table[index] = value;

	return true;
}

void CTable::copyTable() {
	int* temp = new int[tableLength];

	for (int i = 0; i < tableLength; i++) {
		temp[i] = table[i];
	}
	if (modified) {
		delete[] table;
	}
	table = temp;
}

bool CTable::isModified() {
	return modified;
}