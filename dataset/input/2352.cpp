#include <iostream>

class Vehicle {
private: // Semantic Error: startEngine is private, preventing public access
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl;
    }
};

class Car : public Vehicle {
public:
    void startEngine() {
        std::cout << "Car engine started with a roar!" << std::endl;
    }
};

int main() {
    Vehicle v; // This object creation is fine
    std::cout << "Calling startEngine on Vehicle object:" << std::endl;
    // Semantic Error: Attempting to call private method Vehicle::startEngine()
    v.startEngine(); 

    Car c;
    std::cout << "Calling startEngine on Car object:" << std::endl;
    c.startEngine(); // This calls Car::startEngine(), which is public and fine

    // Demonstrate method hiding
    std::cout << "Demonstrating method hiding via Vehicle reference to Car object:" << std::endl;
    Vehicle& v_ref = c;
    // Semantic Error: Attempting to call private method Vehicle::startEngine() via reference
    v_ref.startEngine();

    return 0;
}