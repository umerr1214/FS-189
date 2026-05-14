#include <iostream>
#include <string>

// Base class Vehicle
class Vehicle {
public:
    // Virtual method startEngine
    virtual void startEngine() {
        std::cout << "Vehicle engine starting...\n";
    }
    // Lacks a virtual destructor, which is a robustness issue
    // for polymorphic base classes when objects are deleted via base pointers.
    ~Vehicle() {
        std::cout << "Vehicle destructor called.\n";
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    // Overriding startEngine
    void startEngine() override {
        std::cout << "Car engine starting, vroom vroom!\n";
    }
    ~Car() {
        std::cout << "Car destructor called.\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    // Overriding startEngine
    void startEngine() override {
        std::cout << "Motorcycle engine starting, revving up!\n";
    }
    ~Motorcycle() {
        std::cout << "Motorcycle destructor called.\n";
    }
};

int main() {
    std::cout << "--- Testing Vehicle ---\n";
    Vehicle* genericVehicle = new Vehicle();
    genericVehicle->startEngine();
    delete genericVehicle; // Correctly calls Vehicle destructor

    std::cout << "--- Testing Car ---\n";
    Vehicle* car = new Car(); // Polymorphic pointer
    car->startEngine();
    delete car; // This will only call Vehicle::~Vehicle(), leading to Car::~Car() not being called.
                // This is a memory leak/partial destruction if Car had resources to free.

    std::cout << "--- Testing Motorcycle ---\n";
    Vehicle* motorcycle = new Motorcycle(); // Polymorphic pointer
    motorcycle->startEngine();
    delete motorcycle; // This will only call Vehicle::~Vehicle(), leading to Motorcycle::~Motorcycle() not being called.

    // Also test direct instantiation for completeness, where destructors are called correctly.
    std::cout << "--- Testing direct Car object ---\n";
    Car myCar;
    myCar.startEngine();

    std::cout << "--- Testing direct Motorcycle object ---\n";
    Motorcycle myMotorcycle;
    myMotorcycle.startEngine();

    return 0;
}