#include <iostream>
#include <string>

// Base class
class Vehicle {
private: // Changed to private to highlight the semantic error more clearly
    std::string make;
    int year;

public:
    Vehicle(std::string make_val, int year_val) : make(make_val), year(year_val) {}

    void display() const {
        std::cout << "Make: " << make << ", Year: " << year;
    }
};

// Derived class Car
class Car : public Vehicle {
private:
    int numDoors;

public:
    // SEMANTIC ERROR: Fails to call the base Vehicle constructor in the initializer list.
    // This will cause a compilation error as there is no default constructor for Vehicle.
    Car(std::string make_val, int year_val, int numDoors_val)
        : numDoors(numDoors_val) { // Missing Vehicle(make_val, year_val) here
        // If Vehicle had a default constructor, 'make' and 'year' would be default-initialized
        // and then this body would execute. However, Vehicle only has a parameterized constructor.
        // Attempting to access base class private members directly here would also be a semantic error.
        // this->make = make_val; // Would be an error even if Vehicle had a default constructor
        // this->year = year_val; // Would be an error
    }

    void display() const {
        Vehicle::display();
        std::cout << ", Doors: " << numDoors << std::endl;
    }
};

// Derived class Motorcycle (correctly implemented)
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
    // This line will cause a compilation error due to Car's constructor not calling the base constructor.
    Car myCar("Nissan", 2019, 4);

    // These lines would compile and run correctly if Car didn't have the error.
    Motorcycle myBike("Ducati", 2023, false);

    myCar.display(); // This line will not be reached due to compilation error
    myBike.display();

    return 0;
}