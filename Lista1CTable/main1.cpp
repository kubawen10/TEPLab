#include <iostream>
#include <string>

#include "Tables.h"
#include "CTable.h"

void testEx1();
void testEx2and3();
void v_mod_tab(CTable* pcTab, int iNewSize);
void v_mod_tab(CTable pcTab, int iNewSize);
void testEx4();

int main()
{
	testEx1();
	testEx2and3();
	testEx4();

	return 0;
}

void testEx1() {
	std::cout << "\nEX 1 TESTS\n";

	int tabSize = 3;
	v_alloc_table_fill_34(tabSize);
}

void testEx2and3() {
	std::cout << "\nEX 2 and 3 TESTS\n";
	int** table2d = nullptr;
	int iSizex = 3;
	int iSizey = 5;
	bool success;

	success = b_alloc_table_2_dim(&table2d, iSizex, iSizey);
	std::cout << "Successful allocation: " << success << "\n";

	success = b_dealloc_table_2_dim(&table2d, iSizex);
	std::cout << "Successful deallocation: " << success << "\n";
}

void testEx4() {
	std::cout << "\nEX 4 TESTS\n";

	//default
	CTable tableDefault;

	//params
	CTable tableParams = CTable("Kuba", 15);

	//copy
	CTable tableCopy = CTable(tableParams);

	////change name
	tableCopy.vSetName("Zmiana");

	////change size
	bool success = tableParams.bSetNewSize(5);
	std::cout << "Set size success: " << success << "\n";

	CTable* tableMethodClone = tableDefault.pcClone();
	delete tableMethodClone;

	CTable tableMod = CTable("Modification", 10);
	tableMod.fill();
	std::cout << "Przed modyfikacja: \n";
	tableMod.printTable();

	std::cout << "Modyfikacja wsk: \n";
	v_mod_tab(&tableMod, 8);
	std::cout << "Po modyfikacji wsk: \n";
	tableMod.printTable();

	std::cout << "Modyfikacja bez wsk: \n";
	v_mod_tab(tableMod, 4);
	std::cout << "Po modyfikacji bez wsk: \n";
	tableMod.printTable();

	CTable* tableDynamic;
	tableDynamic = new CTable();
	CTable* tableDynamicCopy = new CTable(*tableDynamic);

	delete tableDynamic;
	delete tableDynamicCopy;

	CTable* tableArray;
	tableArray = new CTable[10];

	delete[] tableArray;


}

void v_mod_tab(CTable* pcTab, int iNewSize) {
	pcTab->bSetNewSize(iNewSize);
}

void v_mod_tab(CTable pcTab, int iNewSize) {
	pcTab.bSetNewSize(iNewSize);
}