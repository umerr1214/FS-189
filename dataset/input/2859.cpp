#include <iostream>
#include <memory> // For std::unique_ptr
#include <vector> // For managing multiple vehicles

// Base class Vehicle
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructed.\n";
    }
    // Virtual destructor is crucial for correct polymorphic cleanup
    virtual ~Vehicle() {
        std::cout << "Vehicle destructed.\n";
    }

    // Virtual method to be overridden by derived classes
    virtual void startEngine() {
        std::cout << "Generic vehicle engine starting...\n";
    }
};

// Derived class Car
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructed.\n";
    }
    ~Car() override { // Use override for clarity and compile-time checks
        std::cout << "Car destructed.\n";
    }

    // Override the base class method
    void startEngine() override {
        std::cout << "Car engine roaring to life!\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    Motorcycle() {
        std::cout << "Motorcycle constructed.\n";
    }
    ~Motorcycle() override { // Use override for clarity and compile-time checks
        std::cout << "Motorcycle destructed.\n";
    }

    // Override the base class method
    void startEngine() override {
        std::cout << "Motorcycle engine kicking over!\n";
    }
};

int main() {
    std::cout << "Demonstrating polymorphic engine starting with correct C++ practices.\n";

    // Use std::unique_ptr for automatic memory management (RAII)
    // std::vector<std::unique_ptr<Vehicle>> vehicles; // A more flexible way to store them

    // Create unique_ptr to Car and Motorcycle, storing them as Vehicle pointers
    std::unique_ptr<Vehicle> myCar = std::make_unique<Car>();
    std::unique_ptr<Vehicle> myMotorcycle = std::make_unique<Motorcycle>();

    std::cout << "\nCalling startEngine() polymorphically:\n";
    myCar->startEngine();
    myMotorcycle->startEngine();

    std::cout << "\nObjects will be automatically destructed when unique_ptr's go out of scope.\n";
    // No explicit delete needed, unique_ptr handles it.
    // The virtual destructor in Vehicle ensures correct derived class destructor is called.

    std::cout << "Program finished.\n";

    return 0;
}