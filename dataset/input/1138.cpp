#include <iostream>

class Vehicle {
protected:
    int speed;
    double fuelLevel;

    void updateSpeed(int newSpeed) {
        speed = newSpeed;
    }

public:
    Vehicle() : speed(0), fuelLevel(100.0) {}
    void displayStatus() const {
        std::cout << "Speed: " << speed << " km/h, Fuel: " << fuelLevel << " L\n";
    }
} // Syntax Error: Missing semicolon after class definition

class Car : public Vehicle {
public:
    void accelerate() {
        if (fuelLevel > 0) {
            updateSpeed(speed + 10); // Increase speed
            fuelLevel -= 1.0;        // Consume fuel
            if (fuelLevel < 0) fuelLevel = 0;
            std::cout << "Car accelerated!\n";
        } else {
            std::cout << "Cannot accelerate, out of fuel!\n";
        }
    }
};

int main() {
    Car myCar;
    myCar.displayStatus();
    myCar.accelerate();
    myCar.displayStatus();
    myCar.accelerate();
    myCar.displayStatus();
    return 0;
}