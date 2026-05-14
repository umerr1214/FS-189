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
};

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
    // LOGICAL ERROR: hasSidecar is always set to true, ignoring the input parameter 'inputHasSidecar'
    Motorcycle(std::string make, int year, bool inputHasSidecar)
        : Vehicle(make, year), hasSidecar(true) {} // Should be hasSidecar(inputHasSidecar)

    void display() const {
        Vehicle::display();
        std::cout << ", Sidecar: " << (hasSidecar ? "Yes" : "No") << std::endl;
    }

    // Getter to allow checking the logical error from outside
    bool getHasSidecar() const {
        return hasSidecar;
    }
};

int main() {
    Car myCar("Honda", 2022, 2);
    myCar.display(); // Expected: Make: Honda, Year: 2022, Doors: 2

    // Test case for logical error:
    // We create a motorcycle *without* a sidecar (input false)
    Motorcycle myBikeWithoutSidecar("Yamaha", 2023, false);
    myBikeWithoutSidecar.display(); // Expected: Sidecar: No. Actual (due to error): Sidecar: Yes.

    // We create a motorcycle *with* a sidecar (input true)
    Motorcycle myBikeWithSidecar("BMW", 2020, true);
    myBikeWithSidecar.display(); // Expected: Sidecar: Yes. Actual: Sidecar: Yes. (Coincidentally correct)

    // Output for JSON driver to parse
    std::cout << "Yamaha_Sidecar:" << (myBikeWithoutSidecar.getHasSidecar() ? "true" : "false") << std::endl;
    std::cout << "BMW_Sidecar:" << (myBikeWithSidecar.getHasSidecar() ? "true" : "false") << std::endl;

    return 0;
}