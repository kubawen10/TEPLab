#include <iostream>
#include <cassert>
#include <string>

#include "CTable.h"

CTable::CTable() {
	sName = DEFAULT_NAME;
	std::cout << "bezp: '" << sName << "'\n";
	tableLength = DEFAULT_TABLE_LENGTH;
	table = new int[tableLength];
}

CTable::CTable(std::string sName, int iTableLen) {
	if (iTableLen < 0) {
		std::cerr << "Wrong table length! Setting default table length";
		tableLength = DEFAULT_TABLE_LENGTH;
	}
	else {
		tableLength = iTableLen;
	}

	this->sName = sName;
	std::cout << "parametr: '" << this->sName << "'\n";

	table = new int[tableLength];
}

CTable::CTable(const CTable& pcOther) {
	sName = pcOther.sName + "_copy";
	tableLength = pcOther.tableLength;
	table = new int[tableLength];
	for (int i = 0; i < tableLength; i++) {
		table[i] = pcOther.table[i];
	}
	std::cout << "Kopiuj: '" << pcOther.sName << "'\n";
}

CTable::~CTable() {
	std::cout << "Usuwam: '" << sName << "'\n";
	delete[] table;
}

void CTable::vSetName(std::string sName) {
	this->sName = sName;
}

bool CTable::bSetNewSize(int iTableLen) {
	if (iTableLen < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (iTableLen == tableLength) {
		return true;
	}

	int smallerTableLength;
	if (tableLength > iTableLen) {
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

void CTable::vSetValueAt(int index, int value) {
	if (index < 0 || index >= tableLength) {
		std::cerr << "wrong index";
		return;
	}

	table[index] = value;
}

void CTable::operator=(const CTable& pcOther)
{
	delete[] table;
	tableLength = pcOther.tableLength;
	table = new int[pcOther.tableLength];

	for (int i = 0; i < tableLength; i++) {
		table[i] = pcOther.table[i];
	}
}

CTable* CTable::operator+(const CTable& tabOther) {
	std::string concatName = sName + " + " + tabOther.sName;
	int concatLength = this->tableLength + tabOther.tableLength;

	CTable* concat = new CTable(concatName, concatLength);
	std::cout << concat->sName << "\n";
	std::cout << concat->tableLength << "\n";

	for (int i = 0; i < this->tableLength; i++) {
		concat->table[i] = this->table[i];
	}

	for (int i = 0; i < tabOther.tableLength; i++) {
		concat->table[i + this->tableLength] = tabOther.table[i];
	}

	return concat;
}
