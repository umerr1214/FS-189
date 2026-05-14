#include <iostream>

// Base class with a non-virtual destructor
class Base {
public:
    Base() {
        std::cout << "Base Constructor Called\n";
    }

    // NON-VIRTUAL destructor - This is the robustness issue
    ~Base() {
        std::cout << "Base Destructor Called\n";
    }
};

// Derived class
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
    std::cout << "Creating Derived object via Base pointer...\n";
    Base* ptr = new Derived(); // Object created on heap

    std::cout << "Deleting object via Base pointer...\n";
    // Due to non-virtual destructor in Base, only Base's destructor will be called.
    // Derived's destructor will NOT be called, leading to a resource leak
    // or undefined behavior if Derived had unique resources.
    delete ptr;

    std::cout << "Demonstration complete.\n";

    return 0;
}