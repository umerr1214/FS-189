#include <iostream>

// Base class with a non-virtual destructor (intended to be fixed)
class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    // ERROR: Missing semicolon after the closing brace of the class definition
    ~Base() {
        std::cout << "Base destructor called." << std::endl;
    }
} 

// Derived class that allocates resources
class Derived : public Base {
private:
    int* data;
public:
    Derived() : Base() {
        data = new int[10]; // Allocate some memory
        std::cout << "Derived constructor called. Allocated 10 ints." << std::endl;
    }
    ~Derived() {
        delete[] data; // Deallocate memory
        std::cout << "Derived destructor called. Deallocated 10 ints." << std::endl;
    }
};

void demonstrate_leak(Base* obj) {
    std::cout << "\n--- Deleting object via Base pointer ---" << std::endl;
    delete obj;
    std::cout << "--- Object deletion complete ---" << std::endl;
}

int main() {
    std::cout << "Scenario: Non-virtual destructor leads to memory leak." << std::endl;
    // This code contains a syntax error and will not compile.
    // If it compiled, the following lines would demonstrate the problem.
    // Base* ptr = new Derived(); // Polymorphic creation
    // demonstrate_leak(ptr);

    // std::cout << "\nScenario: Virtual destructor solves memory leak (conceptually)." << std::endl;

    return 0;
}