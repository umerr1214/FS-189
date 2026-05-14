#include <iostream>

// Base class with a NON-VIRTUAL destructor
class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    ~Base() { // Non-virtual destructor - PROBLEMATIC for polymorphic deletion
        std::cout << "Base destructor called." << std::endl;
    }
};

// Derived class that allocates resources
class Derived : public Base {
private:
    int* data;
public:
    Derived() : Base() {
        data = new int[10]; // Allocate some memory
        std::cout << "Derived constructor called. Allocated 10 ints." << std::endl;
    }
    ~Derived() { // This destructor will NOT be called polymorphically if Base's destructor is non-virtual
        delete[] data; // Deallocate memory
        std::cout << "Derived destructor called. Deallocated 10 ints." << std::endl;
    }
};

void demonstrate_leak(Base* obj) {
    std::cout << "\n--- Deleting object via Base pointer ---" << std::endl;
    delete obj; // SEMANTIC ERROR: Only Base destructor is called, leading to leak
    std::cout << "--- Object deletion complete ---" << std::endl;
}

int main() {
    std::cout << "Scenario: Non-virtual destructor in polymorphic Base class leads to memory leak." << std::endl;
    std::cout << "Expected: Only Base destructor is called, Derived's allocated memory leaks." << std::endl;

    Base* ptr = new Derived(); // Polymorphic creation
    demonstrate_leak(ptr);

    std::cout << "\nExplanation: When deleting a Derived object through a Base pointer, if the Base destructor is not virtual, only the Base destructor is called. This prevents the Derived destructor from executing, leading to a memory leak for resources allocated in Derived." << std::endl;

    return 0;
}