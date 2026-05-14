#include <iostream>
#include <vector>
#include <memory>

// Base class Vehicle
class Vehicle {
public:
    // Semantic Error: Making startEngine pure virtual makes Vehicle an abstract class.
    // The question implies a generic message for Vehicle, not pure virtual.
    virtual void startEngine() = 0; 
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Car engine started. Vroom!" << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Motorcycle engine started. Roar!" << std::endl;
    }
};

int main() {
    // Semantic Error: Cannot instantiate an abstract class 'Vehicle'
    // Vehicle myVehicle; // This line would cause a compilation error
    
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Motorcycle>());

    for (const auto& v : vehicles) {
        v->startEngine();
    }
    return 0;
}