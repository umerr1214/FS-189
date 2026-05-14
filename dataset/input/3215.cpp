#include <iostream>
#include <string>

class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called.\n";
    }
};

class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called.\n";
    }
};

int main() {
    // Logical error: The question asks to illustrate the order when a Car object is created.
    // This code creates a Vehicle object instead of a Car object.
    Vehicle myVehicle; 
    return 0;
}