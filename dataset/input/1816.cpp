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
} // SYNTAX ERROR: Missing semicolon here

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
    SportsCar(int speed, int doors, bool turbo)
        : Car(speed, doors), turboBoostEnabled(turbo) {
        std::cout << "SportsCar constructor: turboBoostEnabled = " << (turboBoostEnabled ? "true" : "false") << std::endl;
    }
    void displaySportsCar() const {
        displayCar();
        std::cout << "Turbo Boost: " << (turboBoostEnabled ? "Enabled" : "Disabled") << std::endl;
    }
};

int main() {
    SportsCar mySportsCar(300, 2, true);
    mySportsCar.displaySportsCar();

    Car myCar(180, 4);
    myCar.displayCar();

    Vehicle myVehicle(120);
    myVehicle.displayVehicle();

    return 0;
}