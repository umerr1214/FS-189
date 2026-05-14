#include <iostream>
#include <string>

class Vehicle {
protected:
    int speed;
    std::string fuelType;

public:
    Vehicle(int s, const std::string& ft) : speed(s), fuelType(ft) {}

    void accelerate() {
        speed -= 10; // LOGICAL ERROR: Speed is decreased instead of increased
        if (speed < 0) speed = 0; // Ensure speed doesn't go negative
        std::cout << "Vehicle accelerating. Speed: " << speed << std::endl;
    }

    void brake() {
        speed -= 5;
        if (speed < 0) speed = 0;
        std::cout << "Vehicle braking. Speed: " << speed << std::endl;
    }

    int getSpeed() const { return speed; }
    std::string getFuelType() const { return fuelType; }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(int s, const std::string& ft, int nd) : Vehicle(s, ft), numDoors(nd) {}

    void honk() {
        std::cout << "Car honking! Beep beep!" << std::endl;
    }

    int getNumDoors() const { return numDoors; }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(int s, const std::string& ft, bool hs) : Vehicle(s, ft), hasSidecar(hs) {}

    void wheelie() {
        std::cout << "Motorcycle doing a wheelie!" << std::endl;
    }

    bool getHasSidecar() const { return hasSidecar; }
};

int main() {
    Car myCar(60, "Gasoline", 4);
    std::cout << "Initial Car speed: " << myCar.getSpeed() << std::endl;
    myCar.accelerate(); // This will incorrectly decrease speed
    myCar.honk();
    std::cout << "Car speed after accelerate: " << myCar.getSpeed() << ", Fuel: " << myCar.getFuelType() << ", Doors: " << myCar.getNumDoors() << std::endl;

    Motorcycle myBike(80, "Petrol", true);
    std::cout << "Initial Motorcycle speed: " << myBike.getSpeed() << std::endl;
    myBike.accelerate(); // This will incorrectly decrease speed
    myBike.wheelie();
    std::cout << "Motorcycle speed after accelerate: " << myBike.getSpeed() << ", Fuel: " << myBike.getFuelType() << ", Sidecar: " << (myBike.getHasSidecar() ? "Yes" : "No") << std::endl;

    return 0;
}