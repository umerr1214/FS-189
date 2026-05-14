#include <iostream>
#include <string>
#include <stdexcept> // For std::invalid_argument exceptions

// Base class: Vehicle
class Vehicle {
protected:
    int maxSpeed; // Maximum speed in km/h

public:
    // Constructor for Vehicle with input validation
    Vehicle(int speed) : maxSpeed(0) { // Initialize to 0, then validate
        if (speed < 0) {
            throw std::invalid_argument("Max speed cannot be negative.");
        }
        this->maxSpeed = speed;
    }

    // Virtual method to display vehicle information
    virtual void displayInfo() const {
        std::cout << "Vehicle:\n";
        std::cout << "  Max Speed: " << maxSpeed << " km/h\n";
    }

    // Getter for maxSpeed
    int getMaxSpeed() const {
        return maxSpeed;
    }
};

// Derived class: Car (inherits from Vehicle)
class Car : public Vehicle {
protected:
    int numDoors; // Number of doors

public:
    // Constructor for Car, chaining to Vehicle constructor with validation
    Car(int speed, int doors) : Vehicle(speed), numDoors(0) { // Initialize to 0, then validate
        if (doors < 0) {
            throw std::invalid_argument("Number of doors cannot be negative.");
        }
        this->numDoors = doors;
    }

    // Override method to display car information
    void displayInfo() const override {
        Vehicle::displayInfo(); // Call base class method
        std::cout << "  Number of Doors: " << numDoors << "\n";
    }

    // Getter for numDoors
    int getNumDoors() const {
        return numDoors;
    }
};

// Derived class: SportsCar (inherits from Car)
class SportsCar : public Car {
private:
    bool turboBoostEnabled; // True if turbo boost is enabled

public:
    // Constructor for SportsCar, chaining to Car constructor
    SportsCar(int speed, int doors, bool turbo)
        : Car(speed, doors), turboBoostEnabled(turbo) {
        // All attributes are initialized via initializer lists or base constructors.
        // Base class constructors handle their own validation.
    }

    // Override method to display sports car information
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
    // Optimize C++ standard streams for performance
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::cout << "--- Demonstrating Multilevel Inheritance ---\n\n";

    // Test Case 1: Valid Vehicle
    try {
        std::cout << "Creating a Vehicle (120 km/h):\n";
        Vehicle v(120);
        v.displayInfo();
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    // Test Case 2: Valid Car
    try {
        std::cout << "Creating a Car (180 km/h, 4 doors):\n";
        Car c(180, 4);
        c.displayInfo();
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    // Test Case 3: Valid SportsCar
    try {
        std::cout << "Creating a SportsCar (250 km/h, 2 doors, turbo enabled):\n";
        SportsCar sc(250, 2, true);
        sc.displayInfo();
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    // Test Case 4: SportsCar with turbo disabled
    try {
        std::cout << "Creating a SportsCar (280 km/h, 2 doors, turbo disabled):\n";
        SportsCar sc2(280, 2, false);
        sc2.displayInfo();
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << "\n\n";
    }

    std::cout << "--- Testing Input Validation (Robustness) ---\n\n";

    // Test Case 5: Invalid Vehicle (negative speed)
    try {
        std::cout << "Attempting to create a Vehicle (-50 km/h):\n";
        Vehicle v_invalid(-50);
        v_invalid.displayInfo(); // This line won't be reached if exception is thrown
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "  Error creating Vehicle: " << e.what() << "\n\n";
    }

    // Test Case 6: Invalid Car (negative doors)
    try {
        std::cout << "Attempting to create a Car (150 km/h, -2 doors):\n";
        Car c_invalid(150, -2);
        c_invalid.displayInfo(); // This line won't be reached
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "  Error creating Car: " << e.what() << "\n\n";
    }

    // Test Case 7: Invalid SportsCar (negative speed and doors)
    try {
        std::cout << "Attempting to create a SportsCar (-100 km/h, -5 doors, turbo enabled):\n";
        SportsCar sc_invalid(-100, -5, true); // Vehicle constructor will throw first
        sc_invalid.displayInfo(); // This line won't be reached
        std::cout << "\n";
    } catch (const std::invalid_argument& e) {
        std::cerr << "  Error creating SportsCar: " << e.what() << "\n\n";
    }

    return 0;
}