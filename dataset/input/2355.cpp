#include <iostream>

class Vehicle {
public:
    void startEngine() {
        std::cout << "Vehicle engine started." << '\n';
    }
};

class Car : public Vehicle {
public:
    void startEngine() { // This method hides Vehicle::startEngine
        std::cout << "Car engine started with a roar!" << '\n';
    }
};

int main() {
    // 1. Demonstrate calling startEngine() on a Vehicle object
    Vehicle myVehicle;
    myVehicle.startEngine();

    // 2. Demonstrate calling startEngine() on a Car object
    Car myCar;
    myCar.startEngine();

    // 3. Demonstrate method hiding (non-virtual overriding) using a base pointer
    // When a base class pointer points to a derived class object,
    // and the method is non-virtual, the base class version of the method is called.
    Vehicle* ptrVehicle = &myCar;
    ptrVehicle->startEngine(); // Calls Vehicle::startEngine

    // 4. Demonstrate method hiding (non-virtual overriding) using a base reference
    // Similarly, when a base class reference refers to a derived class object,
    // and the method is non-virtual, the base class version is called.
    Vehicle& refVehicle = myCar;
    refVehicle.startEngine(); // Calls Vehicle::startEngine

    return 0;
}