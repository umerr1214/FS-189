#include <iostream>
#include <string> // To simulate a resource in Derived

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Problem: Non-virtual destructor.
    // When deleting a Derived object through a Base* pointer,
    // only this destructor will be called, leading to a memory leak
    // if Derived has its own resources.
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
private:
    std::string* resource; // Simulate a dynamically allocated resource
public:
    Derived() : Base(), resource(new std::string("Derived's resource data")) {
        std::cout << "Derived Constructor" << std::endl;
    }
    // This destructor will NOT be called polymorphically if Base's destructor is not virtual.
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
        delete resource; // This memory will leak!
    }
};

void demonstrate_leak() {
    std::cout << "--- Demonstrating Memory Leak (Robustness Issue) ---" << std::endl;
    std::cout << "Creating a Derived object via a Base pointer:" << std::endl;
    Base* ptr = new Derived(); // Allocate Derived object, assign to Base*
    
    std::cout << "\nDeleting the object via the Base pointer:" << std::endl;
    // Only Base's destructor is called, leading to Derived's resource leaking.
    delete ptr;
    
    std::cout << "--- End Demonstration ---" << std::endl;
    std::cout << "Notice: 'Derived Destructor' was NOT called, indicating a memory leak for Derived's resource." << std::endl;
}

int main() {
    demonstrate_leak();
    return 0;
}