#include <iostream>

class Base {
public:
    Base() {
        std::cout << "Base Constructor" << std::endl;
    }
    // Robustness Issue: Destructor is NOT virtual.
    // This can lead to undefined behavior (specifically, Derived's destructor not being called)
    // when a Derived object is deleted via a Base class pointer.
    ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor" << std::endl;
    }
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    // Create a Derived object and manage it via a Base pointer.
    // This setup will expose the robustness issue of the non-virtual base destructor.
    std::cout << "Creating a Derived object via Base pointer (Robustness Issue):\n";
    Base* basePtr = new Derived(); 
    
    // Deleting through a Base pointer when Base's destructor is not virtual
    // results in only Base's destructor being called, potentially leading to resource leaks.
    std::cout << "Deleting the object via Base pointer:\n";
    delete basePtr;

    std::cout << "Observation complete (note missing Derived Destructor).\n";

    return 0;
}