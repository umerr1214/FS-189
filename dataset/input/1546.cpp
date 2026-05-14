#include <iostream>
#include <string>

// Vehicle class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor" << std::endl;
    }
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl;
    }
};

// Car class
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor" << std::endl;
    }
    void drive() {
        std::cout << "Car is driving." << std::endl;
    }
};

// SportsCar class - SYNTAX ERROR: missing semicolon after class definition
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor" << std::endl;
    }
    void activateBoost() {
        std::cout << "SportsCar boost activated!" << std::endl;
    }
} // Semicolon missing here

int main() {
    SportsCar mySportsCar;
    mySportsCar.startEngine();
    mySportsCar.drive();
    mySportsCar.activateBoost();
    return 0;
}