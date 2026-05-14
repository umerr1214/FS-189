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

// Car class - LOGICAL ERROR: Constructor prints wrong name
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Vehicle constructor" << std::endl; // Should print "Car constructor"
    }
    void drive() {
        std::cout << "Car is driving." << std::endl;
    }
};

// SportsCar class - LOGICAL ERROR: Constructor prints wrong name
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "Car constructor" << std::endl; // Should print "SportsCar constructor"
    }
    void activateBoost() {
        std::cout << "SportsCar boost activated!" << std::endl;
    }
};

int main() {
    SportsCar mySportsCar;
    mySportsCar.startEngine();
    mySportsCar.drive();
    mySportsCar.activateBoost();
    return 0;
}