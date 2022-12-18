#ifndef MY_SMART_POINTER_H
#define MY_SMART_POINTER_H

#include <iostream>

class RefCounter
{
public:
	RefCounter() {
		count = 0;
	}

	int add() {
		return(++count);
	}

	int dec() {
		return(--count);
	}

	int get() {
		return(count);
	}
private:
	int count;
};

template <typename T> class MySmartPointer {
public:
	MySmartPointer(T* pointer) {
		this->pointer = pointer;
		counter = new RefCounter();
		counter->add();
	}

	MySmartPointer(const MySmartPointer& other) {
		//difference? (learncpp.com)
		//pointer = new T;
		//*pointer = *other.pointer;

		pointer = other.pointer;
		counter = other.counter;
		counter->add();
	}

	~MySmartPointer() {
		//no need to check for null because it is safe to delete null, checked in the documentation ;)
		if (counter->dec() == 0) {
			delete pointer;
			delete counter;
		}
	}

	MySmartPointer& operator=(const MySmartPointer& other) {
		//self-assignment: pointer1 = pointer1
		if (this == &other) {
			return *this;
		}

		//decrement the counter and delete if neccessery
		~MySmartPointer();

		//update member fields and counter
		pointer = other.pointer;
		counter = other.counter;
		counter->add();
	}

	T& operator*() {  
		return(*pointer); 
	}

	T* operator->() { 
		return(pointer); 
	}

private:
	RefCounter* counter;
	T* pointer;
};


#endif
