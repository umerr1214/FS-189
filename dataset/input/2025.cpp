#include <iostream>

// Base class definition
class Base {
public:
    // Base class constructor
    Base() {
        std::cout << "Base Constructor called." << std::endl;
    }

    // Virtual destructor in Base class is good practice for polymorphism,
    // ensuring correct destruction of derived objects when deleted via a base pointer.
    virtual ~Base() {
        std::cout << "Base Destructor called." << std::endl;
    }
};

// Derived class definition, inheriting from Base
class Derived : public Base {
public:
    // Derived class constructor
    Derived() {
        std::cout << "Derived Constructor called." << std::endl;
    }

    // Derived class destructor, overrides the base virtual destructor
    ~Derived() override {
        std::cout << "Derived Destructor called." << std::endl;
    }
};

int main() {
    std::cout << "--- Demonstrating Constructor and Destructor Order ---" << std::endl;
    std::cout << "Creating a Derived object on the stack..." << std::endl;

    // When an object of a derived class is created:
    // 1. The Base class constructor is called first.
    // 2. Then, the Derived class constructor is called.
    Derived myObject; // Object created on the stack

    std::cout << "Derived object is now in scope. It will go out of scope at the end of main()." << std::endl;

    // When the derived object goes out of scope (at the end of main in this case):
    // 1. The Derived class destructor is called first.
    // 2. Then, the Base class destructor is called.
    std::cout << "Derived object going out of scope..." << std::endl;

    std::cout << "--- End of demonstration ---" << std::endl;
    return 0;
}