#include <iostream>

class Base {
private: // ERROR: Making constructor private
    Base() {
        std::cout << "Base class constructor called." << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived class constructor called." << std::endl;
    }
};

int main() {
    Derived d; // This will fail to compile because Derived cannot call Base's private constructor.
    return 0;
}