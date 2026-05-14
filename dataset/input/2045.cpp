#include <iostream>
#include <string>

class Vehicle {
public:
    int speed;
    std::string color;

    Vehicle(int s, std::string c) : speed(s), color(c) {}
    virtual ~Vehicle() = default;

    void accelerate() {
        speed += 10;
        std::cout << "Vehicle " << color << " accelerates. Speed: " << speed << " km/h\n";
    }

    void displayInfo() const {
        std::cout << "Vehicle Info: Color=" << color << ", Speed=" << speed << " km/h\n";
    }
};

class Car : public Vehicle {
public:
    int numDoors;

    Car(int s, std::string c, int doors) : Vehicle(s, c), numDoors(doors) {}

    void openTrunk() {
        std::cout << "The " << color << " car with " << numDoors << " doors opens its trunk.\n";
    }

    void displayCarInfo() const {
        displayInfo();
        // LOGICAL ERROR: This method always reports 2 doors, regardless of the actual numDoors value.
        std::cout << "  Specific Car Info: Doors=" << 2 << "\n";
    }
};

class Motorcycle : public Vehicle {
public:
    bool hasSidecar;

    Motorcycle(int s, std::string c, bool sidecar) : Vehicle(s, c), hasSidecar(sidecar) {}

    void performWheelie() {
        std::cout << "The " << color << " motorcycle " << (hasSidecar ? "with a sidecar" : "without a sidecar") << " performs a wheelie!\n";
    }

    void displayMotorcycleInfo() const {
        displayInfo();
        std::cout << "  Specific Motorcycle Info: Has Sidecar=" << (hasSidecar ? "Yes" : "No") << "\n";
    }
};

int main() {
    Car myCar(120, "Red", 4);
    myCar.accelerate();
    myCar.displayCarInfo(); // Expected: 4 doors, Actual: 2 doors
    myCar.openTrunk();

    std::cout << "\n";

    Motorcycle myBike(90, "Black", true);
    myBike.accelerate();
    myBike.displayMotorcycleInfo();
    myBike.performWheelie();

    return 0;
}