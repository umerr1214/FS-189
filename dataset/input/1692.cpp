#include <iostream>
#include <string>

// Base class
class Vehicle {
private: // Semantic Error: startEngine() is private
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl;
    }
public:
    // A public method to demonstrate calling startEngine indirectly (if needed),
    // but the direct call from main will fail.
    void prepareForOperation() {
        // This would be fine if startEngine was protected or public,
        // but trying to call it from main directly will fail.
        // startEngine(); // This would be fine if called from a public member function of Vehicle or its friends.
        std::cout << "Vehicle is prepared for operation (engine status unknown due to access restriction)." << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    void drive() {
        // Cannot call startEngine() directly here if it's private in Vehicle
        // startEngine(); // This would cause a compile-time error
        std::cout << "Car is driving." << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    void ride() {
        // Cannot call startEngine() directly here if it's private in Vehicle
        // startEngine(); // This would cause a compile-time error
        std::cout << "Motorcycle is riding." << std::endl;
    }
};

int main() {
    Car myCar;
    Motorcycle myMotorcycle;

    std::cout << "--- Car Actions ---" << std::endl;
    // Semantic Error: Attempting to call private method Vehicle::startEngine()
    myCar.startEngine(); // This line will cause a compile-time semantic error
    myCar.drive();

    std::cout << "\n--- Motorcycle Actions ---" << std::endl;
    // Semantic Error: Attempting to call private method Vehicle::startEngine()
    myMotorcycle.startEngine(); // This line will cause a compile-time semantic error
    myMotorcycle.ride();

    return 0;
}