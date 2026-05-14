#include <iostream>
#include <memory> // Included for general C++ context, though not directly used for the leak in this example

// Base class with a NON-VIRTUAL destructor
class Base {
public:
    Base() {
        std::cout << "Base constructor called.\n";
    }
    // Non-virtual destructor - this is the source of the robustness issue (memory leak)
    ~Base() {
        std::cout << "Base destructor called.\n";
    }
    // A virtual function to make the base class polymorphic for other operations
    virtual void doSomething() const {
        std::cout << "Base is doing something.\n";
    }
};

// Derived class that allocates resources on the heap
class Derived : public Base {
private:
    char* m_resource;
    static const int RESOURCE_SIZE = 1024 * 1024; // 1 MB of data

public:
    Derived() : m_resource(new char[RESOURCE_SIZE]) {
        std::cout << "Derived constructor called. Allocated " << RESOURCE_SIZE << " bytes for m_resource.\n";
        // Initialize resource to avoid garbage values (optional, for clarity)
        for (int i = 0; i < RESOURCE_SIZE; ++i) {
            m_resource[i] = 'X';
        }
    }

    // This destructor will NOT be called when deleting via a Base* pointer if Base's destructor is non-virtual.
    ~Derived() override { // Using override for clarity, though it won't be called polymorphically here
        std::cout << "Derived destructor called. Deallocating m_resource.\n";
        delete[] m_resource;
        m_resource = nullptr;
    }

    void doSomething() const override {
        std::cout << "Derived is doing something specific.\n";
    }
};

int main() {
    std::cout << "--- Scenario: Memory Leak with Non-Virtual Destructor ---\n";
    Base* basePtr = new Derived(); // Create Derived object, pointed to by Base pointer
    basePtr->doSomething(); // This virtual function call works correctly

    std::cout << "Attempting to delete Base pointer...\n";
    // This calls Base's destructor, but NOT Derived's destructor, leading to a memory leak.
    delete basePtr; 
    basePtr = nullptr; // Good practice to nullify after delete

    std::cout << "Deletion complete. Notice 'Derived destructor called' was missing.\n";
    std::cout << "Robustness Issue: " << RESOURCE_SIZE << " bytes allocated by Derived class were leaked.\n";
    std::cout << "This unmanaged memory can lead to resource exhaustion or program instability over time.\n";

    // In a real-world scenario, repeated leaks like this could crash the program or system.
    // For this example, the print statements explicitly highlight the issue.

    return 0;
}