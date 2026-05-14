#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor called." << std::endl;
    }
};

class Derived { // ERROR: Does not inherit from Base
public:
    Derived() {
        std::cout << "Derived class constructor called." << std::endl;
    }
};

int main() {
    Derived d; // This will only call Derived's constructor, not demonstrating inheritance.
    return 0;
}