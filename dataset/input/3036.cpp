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

    // Method to display info - SEMANTIC ERROR: Not declared virtual
    void displayInfo() const { // Missing 'virtual' keyword
        std::cout << "Vehicle Base Info - Brand: " << brand << ", Year: " << year;
    }
};

// Derived Car class
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(const std::string& brand, int year, int numDoors)
        : Vehicle(brand, year), numDoors(numDoors) {}

    // This effectively 'hides' Vehicle::displayInfo, but does not override it polymorphically
    void displayInfo() const {
        Vehicle::displayInfo(); // Call base method (if called directly on Car object)
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

    // This also 'hides' Vehicle::displayInfo
    void displayInfo() const {
        Vehicle::displayInfo(); // Call base method (if called directly on Motorcycle object)
        std::cout << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    Car myCar("Toyota", 2020, 4);
    Motorcycle myMotorcycle("Harley-Davidson", 2022, true);

    // Using base class pointers
    Vehicle* v1 = &myCar;
    Vehicle* v2 = &myMotorcycle;

    std::cout << "--- Calling displayInfo via Base Pointers (Semantic Error) ---" << std::endl;
    // Due to missing 'virtual' in Vehicle::displayInfo,
    // Vehicle::displayInfo() will be called for both, not the derived versions.
    v1->displayInfo(); // This will print "Vehicle Base Info - Brand: Toyota, Year: 2020"
    std::cout << std::endl;
    v2->displayInfo(); // This will print "Vehicle Base Info - Brand: Harley-Davidson, Year: 2022"
    std::cout << std::endl;

    std::cout << "\n--- Calling displayInfo directly on Derived Objects (Correct) ---" << std::endl;
    // Calling directly on derived objects works as expected
    myCar.displayInfo();
    myMotorcycle.displayInfo();

    return 0;
}