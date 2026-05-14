#include <iostream>
#include <string>

// Base class
class Vehicle {
public:
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl;
    }
} // Missing semicolon here

// Derived class Car
class Car : public Vehicle {
public:
    void drive() {
        std::cout << "Car is driving." << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
public:
    void ride() {
        std::cout << "Motorcycle is riding." << std::endl;
    }
};

int main() {
    Car myCar;
    Motorcycle myMotorcycle;

    std::cout << "--- Car Actions ---" << std::endl;
    myCar.startEngine(); // Calling base class method from derived object
    myCar.drive();

    std::cout << "\n--- Motorcycle Actions ---" << std::endl;
    myMotorcycle.startEngine(); // Calling base class method from derived object
    myMotorcycle.ride();

    return 0;
}