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
};

// Derived Car class
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& brand, int year, int numDoors)
        : Vehicle(brand, year), numDoors(numDoors) {}

    // Override displayInfo - LOGICAL ERROR: Does not call Vehicle::displayInfo()
    // It only displays its own attribute, omitting brand and year.
    void displayInfo() const {
        // Vehicle::displayInfo(); // This line is missing, leading to incomplete output
        std::cout << "Car with Doors: " << numDoors << std::endl; // Omits brand and year
    }
};

// Derived Motorcycle class (correct implementation for comparison)
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
    Car myCar("Toyota", 2020, 4);
    std::cout << "Car Info (Logical Error): ";
    myCar.displayInfo(); // Will only show "Car with Doors: 4"

    Motorcycle myMotorcycle("Harley-Davidson", 2022, true);
    std::cout << "Motorcycle Info (Correct): ";
    myMotorcycle.displayInfo(); // Will show full info

    Car anotherCar("Honda", 2018, 2);
    std::cout << "Another Car Info (Logical Error): ";
    anotherCar.displayInfo();

    return 0;
}