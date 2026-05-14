#include <iostream>
#include <string>

// Base class Vehicle
class Vehicle {
public:
    // Virtual method startEngine
    virtual void startEngine() {
        std::cout << "Vehicle engine starting...\n";
    }

    // Virtual destructor is crucial for polymorphic base classes
    // to ensure proper cleanup of derived objects when deleted via base pointers.
    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called.\n";
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    // Overriding startEngine using the 'override' keyword for clarity and safety
    void startEngine() override {
        std::cout << "Car engine starting, vroom vroom!\n";
    }
    ~Car() override { // Mark destructor as override as well (optional but good practice if base has virtual dtor)
        std::cout << "Car destructor called.\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    // Overriding startEngine using the 'override' keyword
    void startEngine() override {
        std::cout << "Motorcycle engine starting, revving up!\n";
    }
    ~Motorcycle() override { // Mark destructor as override
        std::cout << "Motorcycle destructor called.\n";
    }
};

int main() {
    std::cout << "--- Testing Vehicle ---\n";
    Vehicle* genericVehicle = new Vehicle();
    genericVehicle->startEngine();
    delete genericVehicle;

    std::cout << "--- Testing Car ---\n";
    Vehicle* car = new Car(); // Polymorphic pointer
    car->startEngine();
    delete car; // Correctly calls Car::~Car() then Vehicle::~Vehicle()

    std::cout << "--- Testing Motorcycle ---\n";
    Vehicle* motorcycle = new Motorcycle(); // Polymorphic pointer
    motorcycle->startEngine();
    delete motorcycle; // Correctly calls Motorcycle::~Motorcycle() then Vehicle::~Vehicle()

    // Also test direct instantiation for completeness
    std::cout << "--- Testing direct Car object ---\n";
    Car myCar;
    myCar.startEngine();

    std::cout << "--- Testing direct Motorcycle object ---\n";
    Motorcycle myMotorcycle;
    myMotorcycle.startEngine();

    return 0;
}