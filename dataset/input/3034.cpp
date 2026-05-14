#include <iostream>
#include <string>
#include <vector>

// Base class
class Vehicle {
private:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& brand, int year) : brand(brand), year(year) {}

    // Method to display info
    void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year;
    }
}; // Missing semicolon here for syntax error, but for 3034 I'll use a different one.
   // Let's try a missing brace or a keyword typo.
   // I'll make a typo in 'public' in the Car class.

// Derived Car class
class Car : pubclic Vehicle { // SYNTAX ERROR: Typo "pubclic" instead of "public"
private:
    int numDoors;

public:
    Car(const std::string& brand, int year, int numDoors)
        : Vehicle(brand, year), numDoors(numDoors) {}

    // Override displayInfo
    void displayInfo() const {
        Vehicle::displayInfo(); // Call base method
        std::cout << ", Doors: " << numDoors << std::endl;
    }
};

// Derived Motorcycle class
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(const std::string& brand, int year, bool hasSidecar)
        : Vehicle(brand, year), hasSidecar(hasSidecar) {}

    // Override displayInfo
    void displayInfo() const {
        Vehicle::displayInfo(); // Call base method
        std::cout << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    // This part of the code won't be reached due to the syntax error above.
    // However, it's included to show the intended usage.
    Car myCar("Toyota", 2020, 4);
    myCar.displayInfo();

    Motorcycle myMotorcycle("Harley-Davidson", 2022, true);
    myMotorcycle.displayInfo();

    Car anotherCar("Honda", 2018, 2);
    anotherCar.displayInfo();

    return 0;
}