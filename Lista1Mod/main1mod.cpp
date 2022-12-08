#include <iostream>
#include "CTable.h"

int main()
{
	CTable tab1 = CTable("tab1", 5);
	std::cout << "Modified: " << tab1.isModified() << "\n";
	tab1.fill();
	tab1.printTable();
	tab1.writeValue(3, 18);
	tab1.printTable();

	CTable tab2 = CTable(tab1);

	tab2.printTable();
	std::cout << "Modified: " << tab2.isModified() << "\n";

	tab1.writeValue(4, 69);
	tab1.printTable();
	tab2.printTable();

	tab2.writeValue(1, 111);
	tab1.printTable();
	tab2.printTable();
	std::cout << tab2.isModified() << "\n";
}
