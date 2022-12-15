#include <iostream>
#include "MySmartPointer.h"

void testSmartPointer();

int main()
{
    testSmartPointer();
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
