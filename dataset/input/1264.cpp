#include <iostream>

// Base class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor" << std::endl;
    }
    virtual void drive() {
        std::cout << "Driving a Vehicle" << std::endl;
    }
};

// Derived class 1
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }
    void drive() override {
        std::cout << "Driving a Car" << std::endl;
    }
};

// Derived class 2
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor" << std::endl;
    }
    void drive() override {
        std::cout << "Driving a SportsCar" << std::endl;
    }
} // SYNTAX ERROR: Missing semicolon here

int main() {
    std::cout << "--- Creating SportsCar object ---" << std::endl;
    SportsCar mySportsCar;
    std::cout << "--- Calling drive() directly on SportsCar object ---" << std::endl;
    mySportsCar.drive();

    std::cout << "\n--- Demonstrating polymorphism with Vehicle pointer ---" << std::endl;
    Vehicle* vPtr = &mySportsCar;
    vPtr->drive();

    std::cout << "\n--- Demonstrating polymorphism with Car pointer ---" << std::endl;
    Car* cPtr = &mySportsCar;
    cPtr->drive();

    return 0;
}