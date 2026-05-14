#include <iostream>
#include <vector>
#include <memory>

// Base class
class Vehicle {
public:
    virtual void startEngine() {
        std::cout << "Vehicle engine started!" << std::endl;
    }
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Car engine started!" << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Motorcycle engine started!" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    // Demonstrate polymorphic behavior using Vehicle pointers
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Motorcycle>());

    for (const auto& vehicle_ptr : vehicles) {
        vehicle_ptr->startEngine(); // Polymorphic call
    }

    return 0;
}