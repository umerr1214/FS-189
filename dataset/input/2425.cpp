#include <iostream>
#include <string>
#include <vector>

// Base class Vehicle
class Vehicle {
protected:
    int speed;      // Speed in km/h
    std::string fuelType; // Type of fuel (e.g., "Gasoline", "Electric")

public:
    // Constructor - Lacks input validation for speed or fuelType
    Vehicle(int s, std::string ft) : speed(s), fuelType(ft) {
        // No validation: allows negative speed, empty fuelType, etc.
    }

    // Display method
    virtual void display() const {
        std::cout << "Vehicle Type: Generic" << std::endl;
        std::cout << "  Speed: " << speed << " km/h" << std::endl;
        std::cout << "  Fuel Type: " << fuelType << std::endl;
    }
};

// Derived class Car
class Car : public Vehicle {
protected:
    int numDoors; // Number of doors

public:
    // Constructor - Lacks input validation for numDoors
    Car(int s, std::string ft, int nd) : Vehicle(s, ft), numDoors(nd) {
        // No validation: allows negative numDoors
    }

    // Override display method
    void display() const override {
        std::cout << "Vehicle Type: Car" << std::endl;
        std::cout << "  Speed: " << speed << " km/h" << std::endl;
        std::cout << "  Fuel Type: " << fuelType << std::endl;
        std::cout << "  Number of Doors: " << numDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
protected:
    bool hasSidecar; // True if it has a sidecar, false otherwise

public:
    // Constructor
    Motorcycle(int s, std::string ft, bool hs) : Vehicle(s, ft), hasSidecar(hs) {
        // No specific validation needed for bool, but speed/fuelType still unchecked
    }

    // Override display method
    void display() const override {
        std::cout << "Vehicle Type: Motorcycle" << std::endl;
        std::cout << "  Speed: " << speed << " km/h" << std::endl;
        std::cout << "  Fuel Type: " << fuelType << std::endl;
        std::cout << "  Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating Robustness Issue: Lack of input validation" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;

    // Car with invalid data: negative speed, negative doors
    Car invalidCar(-10, "Gasoline", -2);
    std::cout << "\nCreating a Car with invalid speed (-10) and doors (-2):" << std::endl;
    invalidCar.display();

    // Motorcycle with invalid data: negative speed
    Motorcycle invalidMotorcycle(-50, "Electric", true);
    std::cout << "\nCreating a Motorcycle with invalid speed (-50):" << std::endl;
    invalidMotorcycle.display();

    // Car with empty fuel type
    Car emptyFuelCar(120, "", 4);
    std::cout << "\nCreating a Car with empty fuel type:" << std::endl;
    emptyFuelCar.display();

    std::cout << "\nValid vehicles (for comparison):" << std::endl;
    Car normalCar(150, "Gasoline", 4);
    normalCar.display();

    Motorcycle normalMotorcycle(80, "Petrol", false);
    normalMotorcycle.display();

    return 0;
}