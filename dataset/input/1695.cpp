#include <iostream>
#include <string>

// Base class Vehicle
class Vehicle {
public:
    // Method to start the engine
    void startEngine() {
        std::cout << "Vehicle: Engine started." << std::endl;
    }

    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle {
public:
    // Specific method for Car
    void drive() {
        std::cout << "Car: Preparing to drive." << std::endl;
        startEngine(); // Call base class method
        std::cout << "Car: Driving on the road." << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    // Specific method for Motorcycle
    void ride() {
        std::cout << "Motorcycle: Getting ready to ride." << std::endl;
        startEngine(); // Call base class method
        std::cout << "Motorcycle: Riding on the highway." << std::endl;
    }
};

int main() {
    // Demonstrate Car object
    Car myCar;
    std::cout << "--- Demonstrating Car ---" << std::endl;
    myCar.drive(); // Calls drive(), which in turn calls startEngine()
    std::cout << std::endl;

    // Demonstrate Motorcycle object
    Motorcycle myMotorcycle;
    std::cout << "--- Demonstrating Motorcycle ---" << std::endl;
    myMotorcycle.ride(); // Calls ride(), which in turn calls startEngine()
    std::cout << std::endl;

    // Optional: Demonstrate calling startEngine directly from derived objects
    std::cout << "--- Direct startEngine() calls ---" << std::endl;
    myCar.startEngine();
    myMotorcycle.startEngine();
    std::cout << std::endl;

    return 0;
}