#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    int speed; // Unique attribute for Vehicle
public:
    Vehicle(int s) : speed(s) {}

    // Virtual destructor to ensure proper cleanup of derived objects
    virtual ~Vehicle() {
        // std::cout << "Vehicle destructor called." << '\n'; // For debugging/demonstration
    }

    void displayInfo() {
        std::cout << "Vehicle Info: Speed = " << speed << " mph" << '\n';
    }
};

// Derived class from Vehicle
class Car : public Vehicle {
protected:
    int numDoors; // Unique attribute for Car
public:
    Car(int s, int nd) : Vehicle(s), numDoors(nd) {}

    // Virtual destructor (optional for intermediate classes if no new resources, but good practice)
    virtual ~Car() {
        // std::cout << "Car destructor called." << '\n'; // For debugging/demonstration
    }

    void displayInfo() {
        Vehicle::displayInfo(); // Call base Vehicle's displayInfo first
        std::cout << "Car Info: Number of doors = " << numDoors << '\n';
    }
};

// Derived class from Car
class SportsCar : public Car {
protected:
    int spoilerHeight; // Unique attribute for SportsCar
public:
    SportsCar(int s, int nd, int sh) : Car(s, nd), spoilerHeight(sh) {}

    // Virtual destructor
    virtual ~SportsCar() {
        // std::cout << "SportsCar destructor called." << '\n'; // For debugging/demonstration
    }

    void displayInfo() {
        Car::displayInfo(); // Call base Car's displayInfo first (which in turn calls Vehicle's)
        std::cout << "SportsCar Info: Spoiler Height = " << spoilerHeight << " cm" << '\n';
    }
};

int main() {
    // Create an object of the most derived class
    SportsCar mySportsCar(100, 4, 30);
    mySportsCar.displayInfo(); // This will correctly display info from all levels

    // Demonstrating proper cleanup with virtual destructors
    Vehicle* polyVehicle = new SportsCar(120, 2, 40);
    polyVehicle->displayInfo(); // Calls SportsCar's displayInfo due to polymorphism
    delete polyVehicle; // Correctly calls SportsCar, Car, then Vehicle destructors

    return 0;
}