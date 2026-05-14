#include <iostream>
#include <string>
#include <utility> // For std::move

// Base class Vehicle
class Vehicle {
private:
    std::string brand;
    int year;

public:
    // Constructor using initializer list
    Vehicle(std::string brand, int year) : brand(std::move(brand)), year(year) {}

    // Robustness Issue: displayInfo is NOT virtual.
    // This will lead to object slicing/incorrect behavior when called via base pointers.
    void displayInfo() {
        std::cout << "Brand: " << brand << ", Year: " << year << ".\n";
    }

    // Public getters to allow derived classes to access private members for their displayInfo
    std::string getBrand() const { return brand; }
    int getYear() const { return year; }

    // A non-virtual destructor is also a robustness issue if we delete base pointers.
    // However, for this problem, we focus on the displayInfo method.
    ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(std::string brand, int year, int numDoors) : Vehicle(std::move(brand), year), numDoors(numDoors) {}

    // Robustness Issue: This method hides Vehicle::displayInfo() if called via Vehicle*
    // because Vehicle::displayInfo() is not virtual.
    void displayInfo() { // Missing 'override' and base method is not virtual
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Doors: " << numDoors << ".\n";
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(std::string brand, int year, bool hasSidecar) : Vehicle(std::move(brand), year), hasSidecar(hasSidecar) {}

    // Robustness Issue: This method hides Vehicle::displayInfo() if called via Vehicle*
    // because Vehicle::displayInfo() is not virtual.
    void displayInfo() { // Missing 'override' and base method is not virtual
        std::cout << "Brand: " << getBrand() << ", Year: " << getYear() << ", Has Sidecar: " << (hasSidecar ? "Yes" : "No") << ".\n";
    }
};

int main() {
    // Direct objects
    Car myCar("Toyota", 2020, 4);
    Motorcycle myMotorcycle("Harley-Davidson", 2023, true);

    std::cout << "--- Direct Objects ---\n";
    myCar.displayInfo();
    myMotorcycle.displayInfo();

    // Polymorphic objects (Robustness Issue will manifest here)
    // Vehicle* v_car = new Car("Honda", 2018, 2);
    // Vehicle* v_motorcycle = new Motorcycle("BMW", 2022, false);
    // Note: A virtual destructor in Vehicle would be needed for safe deletion of these.
    // For this example, we focus on the displayInfo method's robustness.

    Vehicle* v_car = new Car("Honda", 2018, 2);
    Vehicle* v_motorcycle = new Motorcycle("BMW", 2022, false);

    std::cout << "\n--- Polymorphic Objects (Issue Here) ---\n";
    v_car->displayInfo();       // Calls Vehicle::displayInfo() due to non-virtual base method
    v_motorcycle->displayInfo(); // Calls Vehicle::displayInfo() due to non-virtual base method

    // Clean up
    delete v_car;
    delete v_motorcycle;

    return 0;
}