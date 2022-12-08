#ifndef TABLE_H
#define TABLE_H

#include <string>
const std::string DEFAULT_NAME = "DEFAULT_TABLE_NAME";
const int DEFAULT_TABLE_LENGTH = 10;

template< typename T > class Table
{
public:
	Table();
	Table(std::string name, int tableLen);
	Table(const Table& other);
	~Table();

	void setName(std::string name);
	bool setNewSize(int tableLen);
	Table* clone();

	bool setElement(int index, T value);
	T getElement(int index);

	//debug
	void printTable();

private:
	std::string name;
	int tableLength;
	T* table;
};

template <typename T>
Table<T>::Table() {
	setName(DEFAULT_NAME);
	std::cout << "Bezparametrowy: '" << name << "'\n";
	tableLength = DEFAULT_TABLE_LENGTH;
	table = new T[tableLength];
}

template <typename T>
Table<T>::Table(std::string name, int tableLen) {
	if (tableLen < 0) {
		std::cerr << "Wrong table length! Setting default table length";
		tableLength = DEFAULT_TABLE_LENGTH;
	}
	else {
		this->tableLength = tableLen;
	}

	setName(name);
	std::cout << "Parametrowy: " << name << "\n";

	table = new T[tableLength];
}
template <typename T>
Table<T>::Table(const Table& other) {
	setName(other.name + "_copy");

	tableLength = other.tableLength;
	table = new T[tableLength];

	for (int i = 0; i < tableLength; i++) {
		table[i] = other.table[i];
	}

	std::cout << "Kopiuj: '" << other.name << "'\n";
}
template <typename T>
Table<T>::~Table() {
	std::cout << "Usuwam: '" << name << "'\n";
	delete[] table;
}

template <typename T>
void Table<T>::setName(std::string name) {
	this->name = name;
}

template <typename T>
bool Table<T>::setNewSize(int newTableLength) {
	if (newTableLength < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (newTableLength == tableLength) {
		return true;
	}

	int smallerTableLength;
	if (tableLength > newTableLength) {
		smallerTableLength = newTableLength;
	}
	else {
		smallerTableLength = tableLength;
	}

	tableLength = newTableLength;
	T* newTab = new T[tableLength];

	for (int i = 0; i < smallerTableLength; i++) {
		newTab[i] = table[i];
	}

	delete[] table;
	table = newTab;

	return true;
}

template <typename T>
Table<T>* Table<T>::clone() {
	std::string currentName = name;

	Table<T>* cloneTable = new Table<T>(*this);

	cloneTable->setName(currentName);
	return cloneTable;
}

template <typename T>
bool Table<T>::setElement(int index, T value) {
	if (index < 0 || index >= tableLength) {
		std::cerr << "Wrong index!\n";
		return false;
	}

	table[index] = value;

	return true;
}

template <typename T>
T Table<T>::getElement(int index) {
	if (index < 0 || index >= tableLength) {
		std::cerr << "Wrong index!\n";
		return NULL;
	}

	return table[index];
}

template <typename T>
void Table<T>::printTable() {
	std::cout << name << ": ";
	for (int i = 0; i < tableLength; i++) {
		std::cout << table[i] << " ";
	}
	std::cout << "\n";
}

#endif