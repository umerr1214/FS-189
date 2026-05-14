#include <iostream>
#include <vector>
#include <string>

// Base class
class Vehicle {
public:
    std::string make;
    std::string model;
    int year;

    Vehicle(std::string mk, std::string mdl, int yr)
        : make(mk), model(mdl), year(yr) {}

    // displayInfo() method needs to be virtual
    virtual void displayInfo() const {
        std::cout << "Vehicle: " << year << " " << make << " " << model << std::endl;
    }

    virtual ~Vehicle() {
        std::cout << "Vehicle destructor called for " << make << " " << model << std::endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    int numDoors;

    Car(std::string mk, std::string mdl, int yr, int doors)
        : Vehicle(mk, mdl, yr), numDoors(doors) {}

    // Override displayInfo()
    void displayInfo() const override {
        std::cout << "Car: " << year << " " << make << " " << model << ", Doors: " << numDoors << std::endl;
    }

    ~Car() override {
        std::cout << "Car destructor called for " << make << " " << model << std::endl;
    }
};

int main() {
    // Create an array of Vehicle pointers
    const int NUM_VEHICLES = 3;
    Vehicle* vehicles[NUM_VEHICLES];

    // Point to both Vehicle and Car objects
    vehicles[0] = new Vehicle("Toyota", "Camry", 2020);
    vehicles[1] = new Car("Honda", "Civic", 2022, 4);
    vehicles[2] = new Vehicle("Ford", "F-150", 2021);

    std::cout << "Displaying vehicle information polymorphically:" << std::endl;
    // Logical Error: Loop iterates one element too few, missing the last vehicle
    for (int i = 0; i < NUM_VEHICLES - 1; ++i) { // Should be i < NUM_VEHICLES
        vehicles[i]->displayInfo();
    }

    // Clean up allocated memory
    std::cout << "\nCleaning up memory:" << std::endl;
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        delete vehicles[i];
    }

    return 0;
}