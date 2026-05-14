#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    int speed; // Unique attribute for Vehicle
public:
    Vehicle(int s) : speed(s) {}

    // No virtual destructor - potential robustness issue
    // ~Vehicle() {} 

    void displayInfo() {
        std::cout << "Vehicle Info: Speed = " << speed << " mph" << std::endl;
    }
};

// Derived class from Vehicle
class Car : public Vehicle {
protected:
    int numDoors; // Unique attribute for Car
public:
    Car(int s, int nd) : Vehicle(s), numDoors(nd) {}

    // No virtual destructor - potential robustness issue
    // ~Car() {}

    void displayInfo() {
        Vehicle::displayInfo(); // Calls base Vehicle's displayInfo
        std::cout << "Car Info: Number of doors = " << numDoors << std::endl;
    }
};

// Derived class from Car
class SportsCar : public Car {
protected:
    int spoilerHeight; // Unique attribute for SportsCar
public:
    SportsCar(int s, int nd, int sh) : Car(s, nd), spoilerHeight(sh) {}

    // No virtual destructor - potential robustness issue
    // ~SportsCar() {}

    void displayInfo() {
        // Robustness issue: This method does NOT call Car::displayInfo(),
        // leading to incomplete information being displayed for a SportsCar object
        // if only SportsCar::displayInfo is called.
        // The expectation for multilevel inheritance display is usually to show all levels.
        std::cout << "SportsCar Info: Spoiler Height = " << spoilerHeight << " cm" << std::endl;
    }
};

int main() {
    SportsCar mySportsCar(100, 4, 30);
    mySportsCar.displayInfo(); // This will only show SportsCar info
    
    // Demonstrate the robustness issue with virtual destructors (commented out for compilation)
    // Vehicle* v = new SportsCar(120, 2, 40);
    // delete v; // If Vehicle destructor is not virtual, only Vehicle part is destroyed, leading to memory leak

    return 0;
}