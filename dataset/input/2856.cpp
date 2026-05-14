#include <iostream>
#include <vector>
#include <memory>

// Base class
class Vehicle {
public:
    // SEMANTIC ERROR: 'virtual' keyword is missing.
    // This prevents polymorphic behavior when calling startEngine() via Vehicle pointers.
    void startEngine() {
        std::cout << "Vehicle engine started!" << std::endl;
    }
    virtual ~Vehicle() = default; // Destructor is still virtual for proper cleanup
};

// Derived class Car
class Car : public Vehicle {
public:
    // 'override' keyword must be removed because base method is not virtual.
    // If 'override' were present, it would be a compilation error (Syntax Error).
    void startEngine() {
        std::cout << "Car engine started!" << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    // 'override' keyword must be removed because base method is not virtual.
    void startEngine() {
        std::cout << "Motorcycle engine started!" << std::endl;
    }
};

int main() {
    // Demonstrate polymorphic behavior using Vehicle pointers
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Motorcycle>());

    for (const auto& vehicle_ptr : vehicles) {
        // Due to the missing 'virtual' in Vehicle::startEngine(),
        // Vehicle::startEngine() will be called here, not the derived versions.
        vehicle_ptr->startEngine();
    }

    return 0;
}