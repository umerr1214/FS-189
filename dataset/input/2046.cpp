#include <iostream>
#include <string>
#include <vector> // Used to demonstrate resource that needs cleanup

class Vehicle {
public:
    int speed;
    std::string color;

    Vehicle(int s, std::string c) : speed(s), color(c) {
        std::cout << "Vehicle constructor called for " << color << "\n";
    }
    // SEMANTIC ERROR: Missing 'virtual' keyword for the destructor.
    // When a derived object is deleted via a base class pointer,
    // only the base class destructor will be called, leading to resource leaks
    // if the derived class allocates memory.
    ~Vehicle() {
        std::cout << "Vehicle destructor called for " << color << "\n";
    }

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
    std::vector<std::string>* passengers; // Resource that requires explicit cleanup

    Car(int s, std::string c, int doors) : Vehicle(s, c), numDoors(doors) {
        passengers = new std::vector<std::string>{"Alice", "Bob"};
        std::cout << "Car constructor called for " << color << " with " << numDoors << " doors.\n";
    }

    ~Car() {
        delete passengers; // This destructor will NOT be called if deleted via Vehicle*
        std::cout << "Car destructor called for " << color << ".\n";
    }

    void openTrunk() {
        std::cout << "The " << color << " car with " << numDoors << " doors opens its trunk.\n";
    }

    void displayCarInfo() const {
        displayInfo();
        std::cout << "  Specific Car Info: Doors=" << numDoors << ". Current passengers: " << passengers->size() << "\n";
    }
};

class Motorcycle : public Vehicle {
public:
    bool hasSidecar;

    Motorcycle(int s, std::string c, bool sidecar) : Vehicle(s, c), hasSidecar(sidecar) {
        std::cout << "Motorcycle constructor called for " << color << " with sidecar: " << (sidecar ? "Yes" : "No") << "\n";
    }
    ~Motorcycle() {
        std::cout << "Motorcycle destructor called for " << color << ".\n";
    }

    void performWheelie() {
        std::cout << "The " << color << " motorcycle " << (hasSidecar ? "with a sidecar" : "without a sidecar") << " performs a wheelie!\n";
    }

    void displayMotorcycleInfo() const {
        displayInfo();
        std::cout << "  Specific Motorcycle Info: Has Sidecar=" << (hasSidecar ? "Yes" : "No") << "\n";
    }
};

int main() {
    // Demonstrate the semantic error: deleting a derived object through a base pointer
    // without a virtual destructor in the base class.
    Vehicle* myCarPtr = new Car(120, "Red", 4);
    myCarPtr->accelerate();
    myCarPtr->displayInfo();
    // This will only call Vehicle::~Vehicle(), leading to a memory leak for Car::passengers.
    delete myCarPtr;

    std::cout << "\n";

    Motorcycle myBike(90, "Black", true);
    myBike.accelerate();
    myBike.displayMotorcycleInfo();
    myBike.performWheelie();
    // myBike will be properly destructed when it goes out of scope.

    return 0;
}