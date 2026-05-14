#include <iostream>

class Vehicle {
public:
    void startEngine() {
        std::cout << "Vehicle engine started." << std::endl // Missing semicolon here
    }
};

class Car : public Vehicle {
public:
    void startEngine() {
        std::cout << "Car engine started with a roar!" << std::endl;
    }
};

int main() {
    Vehicle v;
    std::cout << "Calling startEngine on Vehicle object:" << std::endl;
    v.startEngine();

    Car c;
    std::cout << "Calling startEngine on Car object:" << std::endl;
    c.startEngine();

    // Demonstrate method hiding
    std::cout << "Demonstrating method hiding via Vehicle reference to Car object:" << std::endl;
    Vehicle& v_ref = c;
    v_ref.startEngine();

    return 0;
}