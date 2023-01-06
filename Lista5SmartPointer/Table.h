#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <ostream>

const std::string DEFAULT_NAME = "franio";
const int DEFAULT_TABLE_LENGTH = 10;

class Table
{
private:
	std::string name;
	int tableLength;
	int* table;

public:
	Table();
	Table(std::string name, int tableLen);
	Table(const Table& other);
	Table(Table&& other) noexcept;

	~Table();

	Table operator=(const Table& other);
	Table operator=(Table&& other) noexcept;

	Table operator+(const Table& other) const&;

	void setName(std::string newName);
	bool setNewSize(int tableLen);
	void setValueAt(int index, int value);

	int getLength() {
		return tableLength;
	}
	Table* clone();

	//debug
	friend std::ostream& operator<<(std::ostream& out, const Table& table);
	void fill();
};

#endif