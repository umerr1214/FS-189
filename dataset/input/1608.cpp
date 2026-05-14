#include <iostream>
#include <string>

// Vehicle -> Car -> SportsCar hierarchy

class Vehicle {
public:
    Vehicle() { std::cout << "Constructing Vehicle\n"; }
    ~Vehicle() { std::cout << "Destroying Vehicle\n"; } // SEMANTIC ERROR: Destructor is NOT virtual
};

class Car : public Vehicle {
public:
    Car() { std::cout << "Constructing Car\n"; }
    ~Car() override { std::cout << "Destroying Car\n"; }
};

class SportsCar : public Car {
public:
    SportsCar() { std::cout << "Constructing SportsCar\n"; }
    ~SportsCar() override { std::cout << "Destroying SportsCar\n"; }
};

// Function to encapsulate the demonstration logic
void run_destructor_demo() {
    // SEMANTIC ERROR DEMONSTRATION: Deleting a derived object through a base pointer
    // when the base class destructor is not virtual.
    // This leads to undefined behavior; typically, only the base class destructor is called,
    // causing derived class parts to not be properly destructed.
    Vehicle* mySportsCarAsVehicle = new SportsCar(); // Creates SportsCar, Car, Vehicle
    
    // ... use mySportsCarAsVehicle ...

    delete mySportsCarAsVehicle; // Only Vehicle::~Vehicle() is guaranteed to be called due to non-virtual destructor.
                                 // The SportsCar and Car destructors will likely not be called,
                                 // leading to incomplete destruction and resource leaks.
}

int main() {
    run_destructor_demo();
    return 0;
}