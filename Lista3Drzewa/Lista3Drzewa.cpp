#include <iostream>
#include "TreeStatic.h"
#include "TreeDynamic.h"

void zadanie1to3();
void zadanie4();
void testCorrecting();
void testDeleting();
void testAddingWholeTree();
void zadanie6Static();
void zadanie5();
void zadanie6Dynamic();
void testMod();

int main()
{
    zadanie1to3();
    zadanie4();
    testCorrecting();
    testDeleting();
    testAddingWholeTree();
    zadanie6Static();
    zadanie5();
    zadanie6Dynamic();
    testMod();
}

void testMod() {
    NodeStatic root;
    std::cout << "\n";
    root.addNewChild(1);
    root.addNewChild(2);
    std::cout << "\n";
    root.getChild(0)->addNewChild(3);
    root.getChild(0)->addNewChild(4);
    std::cout << "\n";
    root.getChild(1)->addNewChild(5);
    root.getChild(1)->addNewChild(6);
    std::cout << "\n";
    root.getChild(0)->getChild(0)->addNewChild(7);
    root.getChild(0)->getChild(1)->addNewChild(8);

    root.addNewChild(9);
    std::cout << "\n";

    root.printAllBelow();
    std::cout << "\n\n\n";

    std::cout << root.subnodesHaveGoodParentPointer() << "\n";

    root.getChild(1)->setParentToNull();
    std::cout << root.subnodesHaveGoodParentPointer() << "\n";
}

void zadanie6Dynamic() {
    TreeDynamic d1;
    d1.getRoot()->addNewChild(1);
    d1.getRoot()->addNewChild(2);
    d1.getRoot()->addNewChild(3);

    d1.getRoot()->getChild(2)->addNewChild(4);

    TreeDynamic d2;
    d2.getRoot()->setValue(50);
    d2.getRoot()->addNewChild(54);
    d2.getRoot()->addNewChild(55);

    d2.getRoot()->getChild(0)->addNewChild(56);
    d2.getRoot()->getChild(0)->addNewChild(57);
    d2.getRoot()->getChild(0)->getChild(0)->addNewChild(58);

    d1.moveSubtree(d1.getRoot()->getChild(2), d2.getRoot()->getChild(0));
    d1.printTree();
    d2.printTree();
}

void zadanie5() {
    NodeDynamic* r = new NodeDynamic();
    r->addNewChild(1);
    r->addNewChild(2);

    r->getChild(0)->addNewChild(3);
    r->getChild(0)->addNewChild(4);

    r->getChild(1)->addNewChild(5);
    r->getChild(1)->addNewChild(6);

    r->getChild(0)->getChild(0)->addNewChild(7);
    r->getChild(0)->getChild(1)->addNewChild(8);

    r->addNewChild(9);

    r->printAllBelow();

    std::cout << "\n\n\n";

    r->getChild(0)->getChild(0)->getChild(0)->printUp();


    delete r;
}

void zadanie6Static() {
    TreeStatic s1;
    s1.getRoot()->addNewChild(1);
    s1.getRoot()->addNewChild(2);
    s1.getRoot()->addNewChild(3);

    s1.getRoot()->getChild(2)->addNewChild(4);

    TreeStatic s2;
    s2.getRoot()->setValue(50);
    s2.getRoot()->addNewChild(54);
    s2.getRoot()->addNewChild(55);

    s2.getRoot()->getChild(0)->addNewChild(56);
    s2.getRoot()->getChild(0)->addNewChild(57);
    s2.getRoot()->getChild(0)->getChild(0)->addNewChild(58);


    s1.moveSubtree(s1.getRoot()->getChild(2), s2.getRoot()->getChild(0));
    s1.printTree();
    s2.printTree();
}

void testAddingWholeTree() {
    NodeStatic r1;
    r1.addNewChild(1);
    r1.addNewChild(2);
    r1.addNewChild(3);

    r1.getChild(2)->addNewChild(4);

    NodeStatic r2;
    r2.addNewChild(54);
    r2.addNewChild(55);

    r2.getChild(0)->addNewChild(56);
    r2.getChild(0)->addNewChild(57);

    r2.getChild(0)->getChild(0)->addNewChild(58);

    r1.getChild(2)->addNewChild(r2.getChild(0));

    //r1.printAllBelow();
    //r2.printAllBelow();

    //r1.getChild(2)->getChild(1)->getChild(0)->getChild(0)->printUp();
}

void testDeleting() {
    NodeStatic s;
    s.addNewChild(1);
    s.addNewChild(2);
    s.addNewChild(3);
    s.getChild(1)->addNewChild(4);
    s.printAllBelow();

    std::cout << "DELETING\n";
    s.getChild(1)->removeChild(s.getChild(1)->getChild(0));

    s.printAllBelow();
}

void testCorrecting() {
    NodeStatic root;
    std::cout << "\n";
    root.addNewChild(1);
    root.addNewChild(2);
    std::cout << "\n";
    root.getChild(0)->addNewChild(3);
    root.getChild(0)->addNewChild(4);
    std::cout << "\n";
    root.getChild(1)->addNewChild(5);
    root.getChild(1)->addNewChild(6);
    std::cout << "\n";
    root.getChild(0)->getChild(0)->addNewChild(7);
    root.getChild(0)->getChild(1)->addNewChild(8);
    std::cout << "\nNow magic?\n";

    root.addNewChild(9);
    std::cout << "\n";

    root.printAllBelow();
    std::cout << "\n\n\n";

    root.getChild(0)->getChild(0)->getChild(0)->printUp();
    std::cout << "\n\n\n";
    root.getChild(0)->printParent();

}

void zadanie1to3() {
    NodeStatic root;

    root.addNewChild();
    root.addNewChild();
    std::cout << "\n";

    root.getChild(0)->setValue(1);
    root.getChild(1)->setValue(2);
    std::cout << "\n";

    root.getChild(0)->addNewChild();
    root.getChild(0)->addNewChild();
    std::cout << "\n";

    root.getChild(0)->getChild(0)->setValue(11);
    root.getChild(0)->getChild(1)->setValue(12);
    std::cout << "\n";

    root.getChild(1)->addNewChild();
    root.getChild(1)->addNewChild();
    std::cout << "\n";

    root.getChild(1)->getChild(0)->setValue(21);
    root.getChild(1)->getChild(1)->setValue(22);

    //zadanie 2, nie trzeba destruktora poniewaz vector wykonuje to za nas

    //zadanie 3

    root.getChild(0)->getChild(1)->printUp();
}

void zadanie4() {
    TreeStatic t;
    t.getRoot()->addNewChild(1);
    t.getRoot()->addNewChild(2);
    t.getRoot()->getChild(1)->addNewChild(3);
    t.printTree();
}
