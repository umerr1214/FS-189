#include <iostream>

// Base class with a VIRTUAL destructor
class Base {
public:
    Base() {
        std::cout << "Base constructor called." << std::endl;
    }
    virtual ~Base() { // Virtual destructor ensures derived destructor is called
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
    ~Derived() override { // Derived destructor is called due to virtual base destructor
        // LOGICAL ERROR: Forgetting to delete[] data, causing a memory leak
        // The line 'delete[] data;' is intentionally commented out.
        // delete[] data; // This line should be uncommented to fix the leak
        std::cout << "Derived destructor called. (Forgot to deallocate 10 ints!)" << std::endl;
    }
};

void demonstrate_destruction(Base* obj) {
    std::cout << "\n--- Deleting object via Base pointer ---" << std::endl;
    delete obj;
    std::cout << "--- Object deletion complete ---" << std::endl;
}

int main() {
    std::cout << "Scenario: Virtual destructor in Base, but Derived destructor has a logical error." << std::endl;
    std::cout << "Expected: Both Base and Derived destructors are called, but a memory leak still occurs because Derived's destructor is flawed." << std::endl;

    Base* ptr = new Derived(); // Polymorphic creation
    demonstrate_destruction(ptr);

    return 0;
}