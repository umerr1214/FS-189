#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    std::string make;
    std::string model;
public:
    Vehicle(std::string make, std::string model) : make(make), model(model) {}

    void displayInfo() {
        std::cout << "Make: " << make << ", Model: " << model;
    }
};

// Derived class
class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(std::string make, std::string model, int numDoors)
        : Vehicle(make, model), numDoors(numDoors) {}

    void displayInfo() {
        Vehicle::displayInfo();
        std::cout << ", Doors: " << numDoors;
    }
} // Missing semicolon here

int main() {
    Vehicle v("Toyota", "Camry");
    Car c("Honda", "Civic", 4);

    std::cout << "Vehicle Info:" << std::endl;
    v.displayInfo();
    std::cout << std::endl;

    std::cout << "Car Info:" << std::endl;
    c.displayInfo();
    std::cout << std::endl;

    return 0;
}