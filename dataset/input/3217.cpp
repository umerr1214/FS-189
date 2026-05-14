#include <iostream>
#include <string>

// Base class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor" << std::endl;
    }

    // Robustness issue: Missing virtual destructor.
    // If a Car object is deleted via a Vehicle* pointer,
    // the Car destructor will not be called, leading to resource leaks
    // if Car manages its own resources.
    ~Vehicle() {
        std::cout << "Vehicle destructor" << std::endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }

    ~Car() {
        std::cout << "Car destructor" << std::endl;
    }
};

int main() {
    Car myCar; // Illustrates constructor order
    // To demonstrate the robustness issue (memory leak for polymorphic delete):
    // Vehicle* polymorphicCar = new Car();
    // delete polymorphicCar; // Only Vehicle destructor would be called without virtual destructor
    return 0;
}