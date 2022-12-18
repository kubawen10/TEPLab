#include <iostream>
#include <cassert>
#include <string>

#include "Table.h"

Table::Table() {
	name = DEFAULT_NAME;
	std::cout << "bezp: '" << name << "'\n";
	tableLength = DEFAULT_TABLE_LENGTH;
	table = new int[tableLength];
}

Table::Table(std::string name, int tableLength) {
	if (tableLength < 0) {
		std::cerr << "Wrong table length! Setting default table length";
		tableLength = DEFAULT_TABLE_LENGTH;
	}
	else {
		this->tableLength = tableLength;
	}

	this->name = name;
	std::cout << "parametr: '" << this->name << "'\n";

	table = new int[tableLength];
}

Table::Table(const Table& other) {
	name = other.name + "_copy";
	tableLength = other.tableLength;

	table = new int[tableLength];
	for (int i = 0; i < tableLength; i++) {
		table[i] = other.table[i];
	}

	std::cout << "Kopiuj: '" << other.name << "'\n";
}

Table::Table(Table&& other) {
	name = other.name + "_copy";
	tableLength = other.tableLength;

	table = other.table;
	
	other.tableLength = 0;
	other.table = nullptr;

	std::cout << "Kopiuj: '" << other.name << "'\n";
}

Table::~Table() {
	std::cout << "Usuwam: '" << name << "'\n";
	delete[] table;
}

void Table::setName(std::string name) {
	this->name = name;
}

bool Table::setNewSize(int newTableLength) {
	if (newTableLength < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (newTableLength == tableLength) {
		return true;
	}

	int* temp = new int[tableLength];

	int smaller = std::min(tableLength, newTableLength);
	for (int i = 0; i < smaller; i++) {
		temp[i] = table[i];
	}

	delete[] table;
	table = temp;
	tableLength = newTableLength;

	return true;
}

void Table::setValueAt(int index, int value) {
	if (index < 0 || index >= tableLength) {
		std::cerr << "Wrong index!";
		return;
	}

	table[index] = value;
}

Table* Table::clone() {
	return new Table(*this);
}

void Table::operator=(const Table& other)
{
	if (&other == this) {
		return;
	}

	delete[] table;

	tableLength = other.tableLength;
	table = new int[other.tableLength];

	for (int i = 0; i < tableLength; i++) {
		table[i] = other.table[i];
	}
}

void Table::operator=(Table&& other)
{
	if (&other == this) {
		return;
	}

	delete[] table;

	tableLength = other.tableLength;
	table = other.table;

	other.tableLength = 0;
	other.table = nullptr;
}

Table Table::operator+(const Table& other) {
	std::string sumName = name + " + " + other.name;
	int sumLength = tableLength + other.tableLength;

	Table sum(sumName, sumLength);

	for (int i = 0; i < this->tableLength; i++) {
		sum.table[i] = this->table[i];
	}

	for (int i = 0; i < other.tableLength; i++) {
		sum.table[i + this->tableLength] = other.table[i];
	}

	return sum;
}



std::ostream& operator<<(std::ostream& out, const Table& table) {
	out << table.name << ": ";

	if (table.tableLength == 0) {
		out << "Empty";
		return out;
	}

	out << "[";
	for (int i = 0; i < table.tableLength; i++) {
		out << table.table[i];

		if (i == table.tableLength) {
			out << "]";
		}
		else {
			out << ", ";
		}
	}

	return out;
}

void Table::fill() {
	for (int i = 0; i < tableLength; i++) {
		table[i] = i + 1;
	}
}