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
        // Logical Error: Car prints the Motorcycle's message
        std::cout << "Motorcycle engine started. Roar!" << std::endl;
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
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>());
    vehicles.push_back(std::make_unique<Motorcycle>());

    for (const auto& v : vehicles) {
        v->startEngine();
    }
    return 0;
}