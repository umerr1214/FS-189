#include <iostream>

clas Base { // Syntax error: 'clas' instead of 'class'
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Derived d; // Intended to create an object to demonstrate construction/destruction
    return 0;
}