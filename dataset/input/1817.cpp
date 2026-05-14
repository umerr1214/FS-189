#include <iostream>
#include <string>

class Vehicle {
protected:
    int maxSpeed;
public:
    Vehicle(int speed) : maxSpeed(speed) {
        std::cout << "Vehicle constructor: maxSpeed = " << maxSpeed << std::endl;
    }
    void displayVehicle() const {
        std::cout << "Max Speed: " << maxSpeed << " km/h" << std::endl;
    }
};

class Car : public Vehicle {
protected:
    int numDoors;
public:
    Car(int speed, int doors) : Vehicle(speed), numDoors(doors) {
        std::cout << "Car constructor: numDoors = " << numDoors << std::endl;
    }
    void displayCar() const {
        displayVehicle();
        std::cout << "Number of Doors: " << numDoors << std::endl;
    }
};

class SportsCar : public Car {
private:
    bool turboBoostEnabled;
public:
    // LOGICAL ERROR: Passing a hardcoded '0' for speed to Car's constructor,
    // instead of the 'speed' parameter provided to SportsCar.
    // This will cause all SportsCars to have a maxSpeed of 0.
    SportsCar(int speed, int doors, bool turbo)
        : Car(0, doors), turboBoostEnabled(turbo) {
        std::cout << "SportsCar constructor: turboBoostEnabled = " << (turboBoostEnabled ? "true" : "false") << std::endl;
    }
    void displaySportsCar() const {
        displayCar();
        std::cout << "Turbo Boost: " << (turboBoostEnabled ? "Enabled" : "Disabled") << std::endl;
    }
};

int main() {
    SportsCar mySportsCar(300, 2, true); // Intended maxSpeed 300, but will be 0
    mySportsCar.displaySportsCar();

    std::cout << "---" << std::endl;

    Car myCar(180, 4);
    myCar.displayCar();

    std::cout << "---" << std::endl;

    Vehicle myVehicle(120);
    myVehicle.displayVehicle();

    return 0;
}