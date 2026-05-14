#include <iostream>
#include <string>

// Base class
class Vehicle {
protected:
    std::string make;
    int year;

public:
    Vehicle(std::string make, int year) : make(make), year(year) {}

    void display() const {
        std::cout << "Make: " << make << ", Year: " << year;
    }
} // SYNTAX ERROR: Missing semicolon here

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(std::string make, int year, int numDoors)
        : Vehicle(make, year), numDoors(numDoors) {}

    void display() const {
        Vehicle::display();
        std::cout << ", Doors: " << numDoors << std::endl;
    }
};

// Derived class Motorcycle
class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(std::string make, int year, bool hasSidecar)
        : Vehicle(make, year), hasSidecar(hasSidecar) {}

    void display() const {
        Vehicle::display();
        std::cout << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }
};

int main() {
    // This program will fail to compile due to the syntax error.
    // The following lines are for demonstrating the intended use if compiled.
    Car myCar("Toyota", 2020, 4);
    Motorcycle myBike("Harley", 2018, true);

    myCar.display();
    myBike.display();

    return 0;
}