#include <iostream>
#include "CTable.h"

void testEx1to3();
void testEx4();

int main()
{
    testEx1to3();
    testEx4();
}

void testEx1to3() {
    CTable c_tab_0, c_tab_1;
    c_tab_0.bSetNewSize(6);
    c_tab_1.bSetNewSize(4);

    c_tab_0.fill();
    c_tab_1.vSetValueAt(0, 10);
    c_tab_1.vSetValueAt(1, 11);
    c_tab_1.vSetValueAt(2, 12);
    c_tab_1.vSetValueAt(3, 13);
    c_tab_0 = c_tab_1;
    c_tab_0.printTable();
    c_tab_1.printTable();
}

void testEx4() {
    CTable tab1("Tab1", 5);
    CTable tab2("Tab2", 2);
    tab1.fill();
    tab2.vSetValueAt(0, 11);
    tab2.vSetValueAt(1, 12);

    CTable* tab3 = tab1 + tab2;

    tab3->printTable();
    delete tab3;
}

