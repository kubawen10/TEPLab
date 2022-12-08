#ifndef CTABLE_H
#define CTABLE_H

#include <string>
const std::string DEFAULT_NAME = "franio";
const int DEFAULT_TABLE_LENGTH = 10;

class CTable
{
private:
	std::string sName;
	int tableLength;
	int* table;

public:
	CTable();
	CTable(std::string sName, int iTableLen);
	CTable(const CTable& pcOther);
	~CTable();

	void vSetName(std::string sName);
	bool bSetNewSize(int iTableLen);
	CTable* pcClone();

	//debug
	void printTable();
	void fill();
	void vSetValueAt(int index, int value);

	void operator=(const CTable& pcOther);
	CTable* operator+(const CTable& tabOther);
};

#endif