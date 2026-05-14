#include <iostream> // For C++ streams
#include <string>

// Base class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor" << std::endl;
    }

    // Good practice: virtual destructor for polymorphic base classes
    // Ensures correct destructor chain call when deleting derived objects via base pointers.
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor" << std::endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }

    ~Car() override { // Using override keyword for clarity and compile-time checks
        std::cout << "Car destructor" << std::endl;
    }
};

int main() {
    Car myCar; // Create a Car object on the stack to illustrate constructor order
    return 0;
}