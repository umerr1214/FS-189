#include <iostream>
#include <string> // Not strictly needed, but commonly included
#include <vector> // Not strictly needed, but commonly included

// Base class Vehicle
class Vehicle {
protected:
    int maxSpeed; // Maximum speed in km/h

public:
    // Constructor for Vehicle. No validation for maxSpeed.
    Vehicle(int speed) : maxSpeed(speed) {
        // Allows negative speed values, which are illogical but don't cause a crash.
    }

    // Virtual method to display Vehicle information
    virtual void displayInfo() const {
        std::cout << "Vehicle Info:\n";
        std::cout << "  Max Speed: " << maxSpeed << " km/h\n";
    }

    // Getter for maxSpeed
    int getMaxSpeed() const {
        return maxSpeed;
    }
};

// Derived class Car (inherits from Vehicle)
class Car : public Vehicle {
protected:
    int numDoors; // Number of doors

public:
    // Constructor for Car, chaining to Vehicle constructor. No validation for numDoors.
    Car(int speed, int doors) : Vehicle(speed), numDoors(doors) {
        // Allows negative door counts, which are illogical but don't cause a crash.
    }

    // Override method to display Car information
    void displayInfo() const override {
        Vehicle::displayInfo(); // Call base class method
        std::cout << "  Number of Doors: " << numDoors << "\n";
    }

    // Getter for numDoors
    int getNumDoors() const {
        return numDoors;
    }
};

// Derived class SportsCar (inherits from Car)
class SportsCar : public Car {
private:
    bool turboBoostEnabled; // True if turbo boost is enabled

public:
    // Constructor for SportsCar, chaining to Car constructor
    SportsCar(int speed, int doors, bool turbo)
        : Car(speed, doors), turboBoostEnabled(turbo) {
        // All attributes are initialized, but without checks for illogical values
        // passed from the Car or Vehicle constructors.
    }

    // Override method to display SportsCar information
    void displayInfo() const override {
        Car::displayInfo(); // Call base class method
        std::cout << "  Turbo Boost: " << (turboBoostEnabled ? "Enabled" : "Disabled") << "\n";
    }

    // Getter for turboBoostEnabled
    bool isTurboBoostEnabled() const {
        return turboBoostEnabled;
    }
};

int main() {
    // Disable synchronization for faster I/O, a minor optimization.
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    // Test Cases
    std::cout << "--- Test Case 1: Valid Inputs ---\n";
    Vehicle v1(120);
    v1.displayInfo();
    std::cout << "\n";

    Car c1(180, 4);
    c1.displayInfo();
    std::cout << "\n";

    SportsCar sc1(250, 2, true);
    sc1.displayInfo();
    std::cout << "\n";

    // --- Robustness Issue Demonstration: Illogical Inputs ---
    // The program accepts and stores these values without validation,
    // leading to an inconsistent and illogical object state.
    std::cout << "--- Test Case 2: Illogical Negative Max Speed ---\n";
    Vehicle v2(-50); // Max speed cannot be negative in reality
    v2.displayInfo(); // Program displays -50 km/h
    std::cout << "\n";

    std::cout << "--- Test Case 3: Illogical Negative Number of Doors ---\n";
    Car c2(150, -2); // Number of doors cannot be negative
    c2.displayInfo(); // Program displays -2 doors
    std::cout << "\n";

    std::cout << "--- Test Case 4: Combined Illogical Inputs ---\n";
    SportsCar sc2(-100, -5, false); // Both speed and doors are illogical
    sc2.displayInfo(); // Program runs without crashing, but object state is invalid
    std::cout << "\n";

    return 0;
}