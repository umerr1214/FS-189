#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base class constructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived class constructor called." << std::endl;
    }
} // ERROR: Missing semicolon here

int main() {
    Derived d;
    return 0;
}