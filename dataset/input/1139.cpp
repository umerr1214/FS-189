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
};

class Car : public Vehicle {
public:
    void accelerate() {
        if (fuelLevel > 0) {
            updateSpeed(speed + 10); // Increase speed
            fuelLevel -= 1.0;        // Consume fuel
            
            // Logical Error: Fuel magically refills under arbitrary conditions
            if (fuelLevel < 99.0 && speed > 0) { 
                fuelLevel = 100.0; // Reset fuel to full, which is illogical for acceleration
                std::cout << "Fuel magically refilled!\n";
            }

            if (fuelLevel < 0) fuelLevel = 0;
            std::cout << "Car accelerated!\n";
        } else {
            std::cout << "Cannot accelerate, out of fuel!\n";
        }
    }
};

int main() {
    Car myCar;
    myCar.displayStatus(); // Expected: 0, 100
    myCar.accelerate();    // Expected: 10, 99. Actual: 10, 99
    myCar.displayStatus();
    myCar.accelerate();    // Expected: 20, 98. Actual: 20, 100 (due to refill)
    myCar.displayStatus();
    myCar.accelerate();    // Expected: 30, 97. Actual: 30, 99 (98 then refill to 100, then -1 fuel)
    myCar.displayStatus();
    return 0;
}