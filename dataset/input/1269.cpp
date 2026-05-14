#include <iostream>

// Base class: Vehicle
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called." << std::endl;
    }
    // Virtual method for polymorphic behavior
    virtual void drive() const {
        std::cout << "Vehicle is driving." << std::endl;
    }
    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called." << std::endl;
    }
};

// Derived class: Car, inherits from Vehicle
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called." << std::endl;
    }
    // Override keyword ensures method is correctly overriding a virtual base method
    void drive() const override {
        std::cout << "Car is driving." << std::endl;
    }
    // Override destructor
    ~Car() override {
        std::cout << "Car destructor called." << std::endl;
    }
};

// Derived class: SportsCar, inherits from Car
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor called." << std::endl;
    }
    // Override keyword for clarity and compile-time checking
    void drive() const override {
        std::cout << "SportsCar is driving fast!" << std::endl;
    }
    // Override destructor
    ~SportsCar() override {
        std::cout << "SportsCar destructor called." << std::endl;
    }
};

int main() {
    // Demonstrate constructor call order
    std::cout << "\n--- Creating SportsCar object ---" << std::endl;
    SportsCar mySportsCar; // Object created on stack

    // Demonstrate method overriding (direct call)
    std::cout << "\n--- Demonstrating direct drive() method call ---" << std::endl;
    mySportsCar.drive();

    // Demonstrate polymorphic method overriding using base class pointers
    std::cout << "\n--- Demonstrating polymorphic drive() using base pointers ---" << std::endl;
    Vehicle* vehiclePtr = &mySportsCar;
    vehiclePtr->drive(); // Should call SportsCar::drive()

    Car* carPtr = &mySportsCar;
    carPtr->drive(); // Should call SportsCar::drive()
    
    std::cout << "\n--- End of program. Destructors will be called. ---" << std::endl;
    return 0;
}