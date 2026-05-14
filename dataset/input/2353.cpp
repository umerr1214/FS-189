#include <iostream>

// Global flag: A source of robustness issues if not carefully managed.
// Its state can be unexpectedly modified, affecting Vehicle behavior globally.
bool global_vehicle_pre_check_active = false;

class Vehicle {
public:
    void startEngine() {
        if (global_vehicle_pre_check_active) {
            std::cout << "Vehicle engine starting with pre-flight checks..." << '\n';
        } else {
            std::cout << "Vehicle engine started." << '\n';
        }
    }
};

class Car : public Vehicle {
public:
    // This method hides Vehicle::startEngine.
    // It does not depend on the global flag, making its behavior more robust
    // in this specific method, but the base class's behavior is still affected.
    void startEngine() {
        std::cout << "Car engine started with a roar!" << '\n';
    }
};

int main() {
    // Demonstrate Vehicle object
    Vehicle myVehicle;
    global_vehicle_pre_check_active = true; // Activate pre-checks for Vehicle
    myVehicle.startEngine();

    // Demonstrate Car object
    Car myCar;
    global_vehicle_pre_check_active = false; // Deactivate pre-checks, but Car's method ignores it
    myCar.startEngine();

    // Demonstrate method hiding using a base pointer to a derived object
    // The base class method is called, which relies on the global flag.
    Vehicle* ptrVehicle = &myCar;
    global_vehicle_pre_check_active = true; // Re-activate pre-checks for the base method call
    ptrVehicle->startEngine(); // Calls Vehicle::startEngine, which checks the global flag

    // Demonstrate method hiding using a base reference to a derived object
    // The base class method is called, which relies on the global flag.
    Vehicle& refVehicle = myCar;
    global_vehicle_pre_check_active = false; // De-activate pre-checks again
    refVehicle.startEngine(); // Calls Vehicle::startEngine, which checks the global flag

    return 0;
}