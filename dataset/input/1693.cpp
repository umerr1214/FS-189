#include <iostream>
#include <string>
#include <stdexcept> // For std::runtime_error

class Vehicle {
protected:
    int fuelLevel; // Represent fuel level in some units

public:
    Vehicle(int fuel = 100) : fuelLevel(fuel) {}

    void startEngine() {
        if (fuelLevel <= 0) {
            // Robustness issue: Throws an exception without being handled by callers.
            throw std::runtime_error("Engine cannot start: No fuel!");
        }
        std::cout << "Vehicle engine started. Fuel level: " << fuelLevel << std::endl;
    }

    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    Car(int fuel = 120) : Vehicle(fuel) {}

    void drive() {
        // Robustness issue: Calls startEngine() which might throw, but doesn't handle the exception.
        std::cout << "Attempting to drive the car..." << std::endl;
        startEngine(); // This call might throw!
        std::cout << "Car is driving." << std::endl;
    }
};

class Motorcycle : public Vehicle {
public:
    Motorcycle(int fuel = 50) : Vehicle(fuel) {}

    void ride() {
        // Robustness issue: Calls startEngine() which might throw, but doesn't handle the exception.
        std::cout << "Attempting to ride the motorcycle..." << std::endl;
        startEngine(); // This call might throw!
        std::cout << "Motorcycle is riding." << std::endl;
    }
};

int main() {
    // Case 1: Car with enough fuel - should run normally
    Car myCar(80);
    std::cout << "--- Car Test (enough fuel) ---" << std::endl;
    // main doesn't catch here either, but this one won't throw
    myCar.drive(); 
    std::cout << std::endl;

    // Case 2: Motorcycle with enough fuel - should run normally
    Motorcycle myMotorcycle(30);
    std::cout << "--- Motorcycle Test (enough fuel) ---" << std::endl;
    myMotorcycle.ride();
    std::cout << std::endl;

    // Case 3: Car with no fuel - this will cause an unhandled exception and terminate the program.
    Car brokenCar(0);
    std::cout << "--- Car Test (no fuel - EXPECTED CRASH) ---" << std::endl;
    // Robustness issue: This call to drive() will lead to an unhandled exception.
    brokenCar.drive(); 
    std::cout << "This line will not be reached if the program crashes." << std::endl;

    return 0; // This return might not be reached
}