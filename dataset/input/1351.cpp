#include <iostream>
#include <string>
#include <vector> // Using vector for cleaner pointer management, but still introducing a leak

class Vehicle {
protected:
    std::string brand;
    int year;
public:
    Vehicle(std::string brand, int year) : brand(brand), year(year) {}
    virtual ~Vehicle() {
        // No explicit delete for owned resources here, focusing on the main loop leak
    }

    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(std::string brand, int year, int numDoors) : Vehicle(brand, year), numDoors(numDoors) {}
    // No explicit destructor needed here, base destructor is virtual
    
    void displayInfo() const override {
        std::cout << "Brand: " << brand << ", Year: " << year << ", Doors: " << numDoors << std::endl;
    }
};

int main() {
    // Robustness Issue: Memory Leak
    // Objects are dynamically allocated but never deleted.
    // This program will run and produce correct output, but leak memory.

    const int NUM_VEHICLES = 3;
    Vehicle* vehicles[NUM_VEHICLES]; // Using a raw array of pointers

    vehicles[0] = new Vehicle("Truck", 2020);
    vehicles[1] = new Car("Sedan", 2022, 4);
    vehicles[2] = new Vehicle("Motorcycle", 2019);

    std::cout << "Demonstrating polymorphism:" << std::endl;
    for (int i = 0; i < NUM_VEHICLES; ++i) {
        vehicles[i]->displayInfo();
    }

    // MEMORY LEAK: The dynamically allocated Vehicle and Car objects are not deleted.
    // To fix this, a loop like this would be needed:
    // for (int i = 0; i < NUM_VEHICLES; ++i) {
    //     delete vehicles[i];
    // }

    return 0;
}