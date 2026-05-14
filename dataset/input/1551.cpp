#include <iostream>

// Correct Version:
// - Implements the multilevel inheritance hierarchy as requested.
// - Each class has a simple constructor printing its name.
// - Each class has a unique method.
// - Uses a virtual destructor in the base class for proper polymorphic cleanup.
// - Uses `override` keyword for derived class destructors for clarity and safety.
// - Uses `'\n'` for output for better efficiency unless an explicit flush is needed.
// - Follows good C++ practices for naming and formatting.

class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called.\n";
    }
    // Virtual destructor ensures proper cleanup of derived objects when deleted
    // through a base class pointer.
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called.\n";
    }
    void startEngine() {
        std::cout << "Vehicle: Engine started.\n";
    }
};

class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called.\n";
    }
    // Using 'override' keyword explicitly states that this destructor overrides
    // a virtual function from the base class.
    ~Car() override {
        std::cout << "Car destructor called.\n";
    }
    void drive() {
        std::cout << "Car: Driving.\n";
    }
};

class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor called.\n";
    }
    // Using 'override' keyword for clarity.
    ~SportsCar() override {
        std::cout << "SportsCar destructor called.\n";
    }
    void activateBoost() {
        std::cout << "SportsCar: Boost activated!\n";
    }
};

// The main function will be provided in the JSON driver.
// It will demonstrate the correct polymorphic behavior.