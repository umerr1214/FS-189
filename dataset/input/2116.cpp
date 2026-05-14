#include <iostream>
#include <vector>
#include <memory>

// Base class Vehicle
class Vehicle {
public:
    virtual void startEngine() {
        std::cout << "Generic vehicle engine started." << std::endl;
    }
    virtual ~Vehicle() {}
};

// Derived class Car
class Car : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Car engine started. Vroom!" << std::endl;
    }
}; // Missing semicolon here, intentionally causing a syntax error

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    void startEngine() override {
        std::cout << "Motorcycle engine started. Roar!" << std::endl;
    }
};

int main() {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Motorcycle>());

    for (const auto& v : vehicles) {
        v->startEngine();
    }
    return 0;
}