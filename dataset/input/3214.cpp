#include <iostream>
#include <string>

class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called.\n";
    }
    // Missing '}' for Vehicle class
}; // This semicolon is misplaced or closing the wrong block

class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called.\n";
    }
};

int main() {
    Car myCar;
    return 0;
}