#include <iostream>
#include <string>
#include <utility> // For std::move

// Base class Vehicle
class Vehicle {
private:
    std::string brand;
    int year;

public:
    // Constructor using initializer list for efficient member initialization
    Vehicle(std::string brand, int year) : brand(std::move(brand)), year(year) {}

    // Virtual destructor for proper cleanup in polymorphic scenarios
    virtual ~Vehicle() = default;

    // Public getters for derived classes to access private members
    std::string getBrand() const { return brand; }
    int getYear() const { return year; }

    // Virtual method for polymorphic behavior, marked const as it doesn't modify object state
    virtual void displayInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << ".\n";
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // Constructor using initializer list for base and own member
    Car(std::string brand, int year, int numDoors)
        : Vehicle(std::move(brand), year), numDoors(numDoors) {}

    // Override displayInfo, marked const and using '\n' for efficiency
    void displayInfo() const override {
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Doors: " << numDoors << ".\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    // Constructor using initializer list for base and own member
    Motorcycle(std::string brand, int year, bool hasSidecar)
        : Vehicle(std::move(brand), year), hasSidecar(hasSidecar) {}

    // Override displayInfo, marked const and using '\n' for efficiency
    void displayInfo() const override {
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << ".\n";
    }
};

int main() {
    // Create objects directly
    Car myCar("Toyota", 2020, 4);
    Motorcycle myMotorcycle("Harley-Davidson", 2023, true);

    // Create objects polymorphically using base class pointers
    Vehicle* v_car = new Car("Honda", 2018, 2);
    Vehicle* v_motorcycle = new Motorcycle("BMW", 2022, false);

    // Display info for all vehicles, demonstrating correct polymorphic behavior
    myCar.displayInfo();
    myMotorcycle.displayInfo();
    v_car->displayInfo();
    v_motorcycle->displayInfo();

    // Clean up dynamically allocated memory using virtual destructor
    delete v_car;
    delete v_motorcycle;

    return 0;
}