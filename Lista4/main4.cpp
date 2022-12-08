#include <iostream>
#include "Table.h"

int main()
{
    Table<int> tab("A", 3);
    tab.printTable();

    tab.setElement(0, 0);
    tab.setElement(1, 1);
    tab.setElement(2, 2);
    tab.printTable();

    Table<int> copyTab(tab);
    copyTab.printTable();

    Table<int>* cloned = copyTab.clone();
    cloned->printTable();

    delete cloned;

    std::cout << "test";

    return 0;
}

