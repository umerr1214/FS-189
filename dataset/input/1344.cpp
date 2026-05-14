#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    std::string make;
    std::string model;
public:
    Vehicle(std::string make, std::string model) : make(make), model(model) {}

    // Semantic Error: displayInfo is not virtual, preventing true polymorphism
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
};

int main() {
    Vehicle v("Toyota", "Camry");
    Car c("Honda", "Civic", 4);

    std::cout << "Vehicle Info:" << std::endl;
    v.displayInfo();
    std::cout << std::endl;

    std::cout << "Car Info:" << std::endl;
    c.displayInfo();
    std::cout << std::endl;

    // This polymorphic call will demonstrate the semantic error
    // The Vehicle's displayInfo will be called, not Car's, because Vehicle::displayInfo is not virtual.
    Vehicle* v_ptr = &c;
    std::cout << "Polymorphic Call (Car as Vehicle*):" << std::endl;
    v_ptr->displayInfo();
    std::cout << std::endl;

    return 0;
}