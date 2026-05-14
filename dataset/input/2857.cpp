#include <iostream>
#include <vector> // Using vector to manage pointers for demonstration

// Base class Vehicle
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called.\n";
    }
    // Missing virtual destructor - this is the robustness issue
    ~Vehicle() {
        std::cout << "Vehicle destructor called.\n";
    }

    virtual void startEngine() {
        std::cout << "Vehicle engine starting...\n";
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called.\n";
    }
    // Car has a resource that needs cleanup, but base destructor isn't virtual
    ~Car() {
        std::cout << "Car destructor called. (Resource cleanup attempted)\n";
    }

    void startEngine() override {
        std::cout << "Car engine roaring to life!\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        std::cout << "Motorcycle constructor called.\n";
    }
    // Motorcycle has a resource that needs cleanup, but base destructor isn't virtual
    ~Motorcycle() {
        std::cout << "Motorcycle destructor called. (Resource cleanup attempted)\n";
    }

    void startEngine() override {
        std::cout << "Motorcycle engine kicking over!\n";
    }
};

int main() {
    std::cout << "Demonstrating polymorphic engine starting with a robustness issue (missing virtual destructor).\n";
    std::vector<Vehicle*> vehicles;

    // Create objects dynamically
    vehicles.push_back(new Car());
    vehicles.push_back(new Motorcycle());

    std::cout << "\nCalling startEngine() polymorphically:\n";
    for (Vehicle* v : vehicles) {
        v->startEngine();
    }

    std::cout << "\nCleaning up vehicles (watch destructor calls):\n";
    // This will only call Vehicle's destructor, leading to a resource leak
    // for Car and Motorcycle if they had specific cleanup logic in their destructors.
    for (Vehicle* v : vehicles) {
        delete v;
    }

    std::cout << "\nProgram finished.\n";

    return 0;
}