#include <iostream>
#include <string>
#include <iomanip> // For std::fixed and std::setprecision

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
        // Readability/Efficiency Issue: Overly verbose and indirect logic
        // for speed update.
        int currentSpeedValue = this->speed;
        int speedIncreaseFactor = 1;
        int baseAccelerationUnit = 12; // accelerate by 12 km/h
        int calculatedSpeedIncrease = baseAccelerationUnit * speedIncreaseFactor;

        int newCalculatedSpeed = currentSpeedValue + calculatedSpeedIncrease;
        this->updateSpeed(newCalculatedSpeed); // Calls protected method

        // Readability/Efficiency Issue: More verbose fuel adjustment than necessary.
        double initialFuel = this->fuelLevel;
        double fuelReductionPerUnit = 0.3; // Consume 3.0 liters (0.3 * 10)
        double numberOfUnits = 10.0;
        double totalFuelReduction = fuelReductionPerUnit * numberOfUnits;

        // Redundant check that always evaluates true given how totalFuelReduction is calculated
        if (totalFuelReduction > 0.0) {
            this->fuelLevel = initialFuel - totalFuelReduction;
        } else {
            // This branch will never be reached, making it dead code.
            this->fuelLevel = initialFuel;
        }
    }
};

int main() {
    Car myCar(40, 60.0); // Initial speed 40 km/h, fuel 60.0 liters

    std::cout << "Initial State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 1st acceleration
    std::cout << "After 1st accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 2nd acceleration
    std::cout << "After 2nd accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;
              
    std::cout << "Final State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    return 0;
}