#include <iostream>
#include <string>
#include <vector> // For demonstrating polymorphism with pointers
#include <memory> // For std::unique_ptr

// Base class Vehicle
class Vehicle {
protected:
    int speed;      // Speed in km/h
    std::string fuelType; // Type of fuel (e.g., "Gasoline", "Electric")

public:
    // Constructor with proper string passing by const reference
    Vehicle(int s, const std::string& ft) : speed(s), fuelType(ft) {
        // Basic validation could be added here, but not strictly required by the question
    }

    // Virtual destructor for proper cleanup with polymorphism
    virtual ~Vehicle() = default;

    // Virtual display method to allow polymorphism, marked const as it doesn't modify object state
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
    // Constructor
    Car(int s, const std::string& ft, int nd) : Vehicle(s, ft), numDoors(nd) {}

    // Override display method, marked const and using override keyword for clarity
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
    Motorcycle(int s, const std::string& ft, bool hs) : Vehicle(s, ft), hasSidecar(hs) {}

    // Override display method, marked const and using override keyword for clarity
    void display() const override {
        std::cout << "Vehicle Type: Motorcycle" << std::endl;
        std::cout << "  Speed: " << speed << " km/h" << std::endl;
        std::cout << "  Fuel Type: " << fuelType << std::endl;
        std::cout << "  Has Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    std::cout << "Demonstrating Correct Version: Proper Class Design and Polymorphism" << std::endl;
    std::cout << "-----------------------------------------------------------------" << std::endl;

    // Using smart pointers for automatic memory management and polymorphism
    std::vector<std::unique_ptr<Vehicle>> vehicles;

    vehicles.push_back(std::make_unique<Car>(180, "Gasoline", 4));
    vehicles.push_back(std::make_unique<Motorcycle>(100, "Petrol", true));
    vehicles.push_back(std::make_unique<Car>(90, "Electric", 2));
    vehicles.push_back(std::make_unique<Motorcycle>(120, "Diesel", false));

    for (const auto& vehicle : vehicles) {
        std::cout << "\n";
        vehicle->display();
    }

    std::cout << "\nAll vehicles displayed successfully." << std::endl;

    return 0;
}