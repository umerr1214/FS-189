#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision
#include <algorithm> // For std::min/max

class Vehicle {
protected:
    int speed;      // km/h
    double fuelLevel; // liters

protected:
    void updateSpeed(int newSpeed) {
        speed = newSpeed;
    }

public:
    Vehicle(int initialSpeed = 0, double initialFuel = 100.0)
        : speed(initialSpeed), fuelLevel(initialFuel) {}

    // Public getters for testing purposes
    int getSpeed() const { return speed; }
    double getFuelLevel() const { return fuelLevel; }
};

class Car : public Vehicle {
public:
    Car(int initialSpeed = 0, double initialFuel = 100.0)
        : Vehicle(initialSpeed, initialFuel) {}

    void accelerate() {
        const int ACCELERATION_AMOUNT = 15; // Moderate acceleration
        const double FUEL_CONSUMPTION = 3.0; // Moderate fuel consumption
        const int MAX_SPEED = 200; // Realistic maximum speed
        const int MIN_SPEED = 0; // Realistic minimum speed (not explicitly needed for accelerate, but good practice)
        const double MIN_FUEL_LEVEL = 0.0; // Fuel cannot go below 0

        // Check if there's enough fuel to accelerate
        if (fuelLevel <= MIN_FUEL_LEVEL) {
            // Cannot accelerate if fuel is depleted
            // Optionally, print a message
            // std::cout << "Cannot accelerate: Fuel is empty." << std::endl;
            fuelLevel = MIN_FUEL_LEVEL; // Ensure fuel doesn't go negative if it was just below 0 due to precision
            return;
        }

        // Calculate potential new speed
        int potentialNewSpeed = speed + ACCELERATION_AMOUNT;

        // Clamp speed to MAX_SPEED
        updateSpeed(std::min(potentialNewSpeed, MAX_SPEED));

        // Adjust fuel level, ensuring it doesn't go below MIN_FUEL_LEVEL
        fuelLevel = std::max(MIN_FUEL_LEVEL, fuelLevel - FUEL_CONSUMPTION);
    }
};

int main() {
    Car myCar(150, 10.0); // Initial speed 150 km/h, fuel 10.0 liters

    std::cout << "Initial State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 1st acceleration
    std::cout << "After 1st accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 2nd acceleration
    std::cout << "After 2nd accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 3rd acceleration (speed approaches max, fuel approaches min)
    std::cout << "After 3rd accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 4th acceleration (fuel becomes 0, speed hits max)
    std::cout << "After 4th accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 5th acceleration (no change due to empty fuel)
    std::cout << "After 5th accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;
              
    std::cout << "Final State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    return 0;
}