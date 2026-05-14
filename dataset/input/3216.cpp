#include <iostream>
#include <string>

class Vehicle {
private: // Semantic error: Making constructor private
    Vehicle() {
        std::cout << "Vehicle constructor called.\n";
    }
public:
    // No public constructor is provided, so the private one is the only default.
    // This will cause an access error when Car tries to call it.
};

class Car : public Vehicle {
public:
    Car() {
        // This implicitly tries to call Vehicle::Vehicle(), which is private.
        // This will result in a compiler error due to inaccessible base constructor.
        std::cout << "Car constructor called.\n";
    }
};

int main() {
    Car myCar; // This line will cause a compilation error
    return 0;
}