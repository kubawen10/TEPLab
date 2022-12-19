#include <iostream>
#include <utility>

#include "MySmartPointer.h"
#include "Tab.h"

void testSmartPointer();
void testEx4();

int main()
{
    //testSmartPointer(); //ex 1-3
    testEx4();
}

void testSmartPointer() {
    int* a = new int(11);
    MySmartPointer<int> pa(a);

    //copy constructor test
    MySmartPointer<int> paCopy(pa);

    //operator= test
    MySmartPointer<int> b = paCopy;

    std::cout << "Value of b: " << *b << '\n';

    //operator-> test
    class Foo {
    public:
        Foo() {}

        void print() {
            std::cout << "im class a\n";
        }
    };
    Foo* foo = new Foo();
    MySmartPointer<Foo> fooPointer(foo);
    fooPointer->print();

    //static memory allocation doesnt work 
    //we delete the pointer which wasnt created with new
}

void ex4MoveConstructor() {
    std::cout << "\n\nMOVE CONSTRUCTOR DEMO\n\n";
    Tab t1;
    t1.fill();

    std::cout << "Normal copy constructor\n";
    std::cout << "t1: " << t1 << "\n";
    Tab t2(t1);
    std::cout << "\nt1 after: " << t1 << "\n";
    std::cout << "t2 after: " << t2 << "\n\n";


    std::cout << "Move copy constructor\n";
    std::cout << "t1: " << t1 << "\n";
    Tab t3(std::move(t1));
    std::cout << "\nt1 after: " << t1 << "\n";
    std::cout << "t3 after: " << t3 << "\n\n";

    std::cout << "\n\nEND MOVE CONSTRUCTOR DEMO\n\n";
}

void ex4MoveOperator() {
    std::cout << "\n\nMOVE OPERATOR= DEMO\n\n";


    Tab t1;
    Tab t2;
    Tab t3;
    t1.fill();
    t2.setSize(5);
    t2.fill();
    t3.setSize(15);
    t3.fill();

    std::cout << "Normal operator=\n";
    std::cout << "t1: " << t1 << "\n";
    std::cout << "t2: " << t2 << "\n";
    std::cout << "t3: " << t3 << "\n\n";

    t1 = t2 = t3;
    std::cout << "\nt1 after: " << t1 << "\n";
    std::cout << "t2 after: " << t2 << "\n";
    std::cout << "t3 after: " << t3 << "\n\n";


    std::cout << "\nMove operator=\n";
    t1.setSize(10);
    t1.fill();

    std::cout << "t1: " << t1 << "\n";
    std::cout << "t2: " << t2 << "\n\n";
    t1 = std::move(t2);
    std::cout << "\nt1 after: " << t1 << "\n";
    std::cout << "t2 after: " << t2 << "\n\n";


    std::cout << "\nEND MOVE OPERATOR= DEMO\n";
}

void testEx4() {
    ex4MoveOperator();
    //ex4MoveConstructor();
}
