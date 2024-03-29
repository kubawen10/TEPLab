#include <iostream>
#include <cassert>
#include <string>

#include "Table.h"

Table::Table() {
	name = DEFAULT_NAME;
	tableLength = DEFAULT_TABLE_LENGTH;
	table = new int[tableLength];

	std::cout << "Default out\n";
}

Table::Table(std::string name, int tableLength) {
	this->name = name;

	if (tableLength < 0) {
		std::cerr << "Wrong table length! Setting default table length";
		tableLength = DEFAULT_TABLE_LENGTH;
	}
	else {
		this->tableLength = tableLength;
	}
	table = new int[tableLength];

	std::cout << "Param constructor " << this->name << " out\n";
}

Table::Table(const Table& other) {
	name = other.name + "_copy";
	tableLength = other.tableLength;

	table = new int[tableLength];
	for (int i = 0; i < tableLength; i++) {
		table[i] = other.table[i];
	}

	std::cout << "Copy constructor " << other.name << " out\n";
}

Table::Table(Table&& other) noexcept{
	name = other.name + "_copyMove";
	table = other.table;
	tableLength = other.tableLength;
	
	other.table = nullptr;
	other.tableLength = 0;

	std::cout << "Move copy constructor " << name << " out\n";
}

Table::~Table() {
	std::cout << "Destructor " << name << "\n";
	delete[] table;
}

void Table::setName(std::string newName) {
	name = newName;
}

bool Table::setNewSize(int newTableLength) {
	if (newTableLength < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (newTableLength == tableLength) {
		return true;
	}

	int* temp = new int[newTableLength];

	int smaller = tableLength < newTableLength ? tableLength : newTableLength;
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

//return std::move() nie ma sensu
//moze jakby stworzyc nowy obiekt i zwracac go poprzez std::move
Table Table::operator=(const Table& other)
{
	if (&other == this) {
		return *this;
	}

	delete[] table;

	tableLength = other.tableLength;

	table = new int[tableLength];
	for (int i = 0; i < tableLength; i++) {
		table[i] = other.table[i];
	}

	std::cout << "operator= out\n";
	return *this;
}

//return std::move() nie ma sensu
//moze jakby stworzyc nowy obiekt i zwracac go poprzez std::move
Table Table::operator=(Table&& other) noexcept
{
	if (&other == this) {
		return *this;
	}

	delete[] table;

	table = other.table;
	tableLength = other.tableLength;

	other.table = nullptr;
	other.tableLength = 0;

	std::cout << "move operator= out\n";
	return *this;
}



Table Table::operator+(const Table& other) const{
	std::string sumName = name + " + " + other.name;
	int sumLength = tableLength + other.tableLength;

	Table sum(sumName, sumLength);

	for (int i = 0; i < tableLength; i++) {
		sum.table[i] = table[i];
	}

	for (int i = 0; i < other.tableLength; i++) {
		sum.table[i + tableLength] = other.table[i];
	}

	std::cout << "operator+ out\n";
	return (std::move(sum));
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

		if (i == table.tableLength - 1) {
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