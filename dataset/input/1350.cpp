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

    // Semantic Error: displayInfo() method is NOT virtual,
    // which prevents polymorphic behavior through base pointers.
    void displayInfo() const { // Missing 'virtual' keyword
        std::cout << "Vehicle: " << year << " " << make << " " << model << std::endl;
    }

    virtual ~Vehicle() { // Destructor is virtual for correct cleanup, but displayInfo is not
        std::cout << "Vehicle destructor called for " << make << " " << model << std::endl;
    }
};

// Derived class
class Car : public Vehicle {
public:
    int numDoors;

    Car(std::string mk, std::string mdl, int yr, int doors)
        : Vehicle(mk, mdl, yr), numDoors(doors) {}

    // This method 'hides' Vehicle::displayInfo() rather than overriding it polymorphically
    void displayInfo() const override { // 'override' keyword is valid, but doesn't make it virtual if base isn't
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
    // Call displayInfo() through base pointers
    // Due to missing 'virtual' in Vehicle, Vehicle::displayInfo() will always be called
    // for Car objects as well, demonstrating static binding (slicing)
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        vehicles[i]->displayInfo();
    }

    // Clean up allocated memory
    std::cout << "\nCleaning up memory:" << std::endl;
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        delete vehicles[i];
    }

    return 0;
}