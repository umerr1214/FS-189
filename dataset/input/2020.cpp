#include <iostream>

// Base class definition
class Base {
public:
    Base() {
        std::cout << "Base Constructor Called\n";
    }
    ~Base() {
        std::cout << "Base Destructor Called\n";
    }
} // Missing semicolon here, causing a syntax error

// Derived class definition
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor Called\n";
    }
    ~Derived() {
        std::cout << "Derived Destructor Called\n";
    }
};

int main() {
    std::cout << "Program Start: Creating Derived object...\n";
    { // A block to clearly define the scope of the Derived object
        Derived d;
    } // 'd' goes out of scope here, triggering destructors
    std::cout << "Program End: Derived object went out of scope.\n";
    return 0;
}