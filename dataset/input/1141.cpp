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
        int accelerationAmount = 25; // Accelerate by 25 km/h
        double fuelConsumption = 6.0; // Consume 6.0 liters per acceleration

        // Robustness Issue 1: Speed can go indefinitely high without a maximum limit.
        updateSpeed(speed + accelerationAmount);

        // Robustness Issue 2: Fuel level can go negative without handling.
        fuelLevel -= fuelConsumption;

        // No checks for fuelLevel becoming negative or speed exceeding a practical maximum.
    }
};

int main() {
    Car myCar(60, 20.0); // Initial speed 60 km/h, fuel 20.0 liters

    std::cout << "Initial State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 1st acceleration
    std::cout << "After 1st accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 2nd acceleration
    std::cout << "After 2nd accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 3rd acceleration (fuel becomes negative here)
    std::cout << "After 3rd accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    myCar.accelerate(); // 4th acceleration (speed becomes very high)
    std::cout << "After 4th accelerate: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;
              
    std::cout << "Final State: Speed=" << myCar.getSpeed()
              << ", Fuel=" << std::fixed << std::setprecision(1) << myCar.getFuelLevel() << std::endl;

    return 0;
}