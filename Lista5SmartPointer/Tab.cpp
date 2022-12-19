#include "Tab.h"
#include <iostream>

Tab::Tab(const Tab& other)
{
	std::cout << "Copy constructor in\n";
	copy(other);
	std::cout << "Copy Constructor out\n";
}

Tab::Tab(Tab&& other) 
{
	std::cout << "Move constructor in\n";
	tab = other.tab;
	size = other.size;

	other.tab = nullptr;
	other.size = 0;

	std::cout << "Move constructor out\n";
}

Tab Tab::operator=(const Tab& other)
{
	std::cout << "op=& in\n";
	if (&other == this) {
		return *this;
	}

	delete[] tab;

	copy(other);

	std::cout << "op=& out\n";
	return *this;
}

Tab Tab::operator=(Tab&& other)
{
	std::cout << "op=&& in\n";
	if (&other == this) {
		return *this;
	}

	delete[] tab;

	tab = other.tab;
	size = other.size;

	other.tab = nullptr;
	other.size = 0;

	std::cout << "op=&& out\n";
	return std::move(*this);
}

Tab::~Tab()
{
	delete[] tab;

	std::cout <<"Destructor \n";
}

bool Tab::setSize(int newSize)
{
	if (newSize < 0) {
		std::cerr << "Table length cannot be less than 0!\n";
		return false;
	}

	if (size == newSize) {
		return true;
	}

	int* temp = new int[newSize];
	int smaller = std::min(size, newSize);
	for (int i = 0; i < smaller; i++)
	{
		temp[i] = tab[i];
	}

	delete[] tab;
	tab = temp;
	size = newSize;

	return true;
}

void Tab::fill() {
	for (int i = 0; i < size; i++)
	{
		tab[i] = i + 1;
	}
}

void Tab::copy(const Tab& other)
{
	tab = new int[other.size];
	size = other.size;

	for (int i = 0; i < other.size; i++)
	{
		tab[i] = other.tab[i];
	}

	std::cout << "Copy\n";
}

std::ostream& operator<<(std::ostream& out, const Tab& table) {
	out << "Table: ";

	if (table.size == 0) {
		out << "Empty";
		return out;
	}


	out << "[";
	for (int i = 0; i < table.size; i++) {
		out << table.tab[i];

		if (i == table.size - 1) {
			out << "]";
		}
		else {
			out << ", ";
		}
	}

	return out;
}
