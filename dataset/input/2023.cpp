#include <iostream>
#include <vector> // Unused, but often part of larger projects where robustness issues manifest

// Base class with a non-virtual destructor
class Base {
public:
    Base() {
        std::cout << "Base Constructor called." << std::endl;
    }

    // NON-VIRTUAL destructor - This is the robustness issue
    ~Base() {
        std::cout << "Base Destructor called." << std::endl;
    }

    void someBaseFunction() {
        std::cout << "Base function called." << std::endl;
    }
};

// Derived class
class Derived : public Base {
public:
    Derived() {
        std::cout << "Derived Constructor called." << std::endl;
    }

    ~Derived() {
        std::cout << "Derived Destructor called." << std::endl;
    }

    void someDerivedFunction() {
        std::cout << "Derived function called." << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Robustness Issue: Non-virtual Base Destructor ---" << std::endl;
    std::cout << "Creating Derived object via Base pointer..." << std::endl;

    // Allocate a Derived object dynamically and point to it with a Base pointer
    Base* obj = new Derived(); 

    obj->someBaseFunction(); // This is fine

    std::cout << "Deleting object via Base pointer..." << std::endl;
    // When deleting through a Base* pointer, if Base's destructor is not virtual,
    // only the Base destructor is called, leading to an incomplete destruction
    // of the Derived part and potential resource leaks or undefined behavior.
    delete obj; 

    std::cout << "--- End of demonstration ---" << std::endl;

    return 0;
}