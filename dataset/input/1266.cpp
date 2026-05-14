#include <iostream>

// Base class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor" << std::endl;
    }
    // SEMANTIC ERROR: drive() is NOT virtual.
    // This prevents polymorphic behavior when called via base pointers/references.
    void drive() {
        std::cout << "Driving a Vehicle" << std::endl;
    }
};

// Derived class 1
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }
    // This method 'hides' Vehicle::drive(), it does not 'override' it.
    void drive() {
        std::cout << "Driving a Car" << std::endl;
    }
};

// Derived class 2
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor" << std::endl;
    }
    // This method 'hides' Car::drive(), it does not 'override' it.
    void drive() {
        std::cout << "Driving a SportsCar" << std::endl;
    }
};

int main() {
    std::cout << "--- Creating SportsCar object ---" << std::endl;
    SportsCar mySportsCar;
    std::cout << "--- Calling drive() directly on SportsCar object ---" << std::endl;
    mySportsCar.drive(); // Calls SportsCar::drive() as expected

    std::cout << "\n--- Demonstrating semantic error: calling drive() via base pointer ---" << std::endl;
    Vehicle* vPtr = &mySportsCar; // Base pointer to derived object
    // SEMANTIC ERROR: Calls Vehicle::drive() due to static binding (non-virtual function).
    // Expected: SportsCar::drive(). Actual: Vehicle::drive().
    vPtr->drive();

    std::cout << "\n--- Calling drive() via intermediate base pointer ---" << std::endl;
    Car* cPtr = &mySportsCar;
    // SEMANTIC ERROR: Calls Car::drive() due to static binding (non-virtual function).
    // Expected: SportsCar::drive(). Actual: Car::drive().
    cPtr->drive();

    return 0;
}