#include <iostream>
#include "TreeDynamic.h"

int main()
{
    TreeDynamic<double> d1;

    d1.getRoot()->setValue(0);
    d1.getRoot()->addNewChild(1);
    d1.getRoot()->addNewChild(2);
    d1.getRoot()->addNewChild(3);
    d1.getRoot()->getChild(2)->addNewChild(4);

    TreeDynamic<double> d2;
    d2.getRoot()->setValue(50);
    d2.getRoot()->addNewChild(54);
    d2.getRoot()->addNewChild(55);

    d2.getRoot()->getChild(0)->addNewChild(56);
    d2.getRoot()->getChild(0)->addNewChild(57);
    d2.getRoot()->getChild(0)->getChild(0)->addNewChild(58);


    d1.moveSubtree(d1.getRoot()->getChild(2), d2.getRoot()->getChild(0));
    d1.printTree();
    d2.printTree();

    return 0;
}


