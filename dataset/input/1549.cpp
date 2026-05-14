#include <iostream>

// Robustness Issue: Non-virtual destructor in the base class.
// This leads to undefined behavior or resource leaks when deleting
// derived objects through a base class pointer.

class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor\n";
    }
    // This destructor should be virtual for proper polymorphic cleanup.
    // Without 'virtual', only Vehicle's destructor will be called when
    // deleting a derived object via a Vehicle* pointer.
    ~Vehicle() {
        std::cout << "Vehicle destructor\n";
    }
    void startEngine() {
        std::cout << "Vehicle engine started.\n";
    }
};

class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor\n";
    }
    ~Car() {
        std::cout << "Car destructor\n";
    }
    void drive() {
        std::cout << "Car is driving.\n";
    }
};

class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor\n";
    }
    ~SportsCar() {
        std::cout << "SportsCar destructor\n";
    }
    void activateBoost() {
        std::cout << "SportsCar boost activated!\n";
    }
};

// The main function will be provided in the JSON driver.
// It will demonstrate the destructor issue.
// Expected output will show that Car and SportsCar destructors are NOT called.
// Example: Vehicle* myVehicle = new SportsCar(); delete myVehicle;
// This should print constructors for Vehicle, Car, SportsCar,
// then only the destructor for Vehicle.