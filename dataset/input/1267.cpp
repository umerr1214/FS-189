#include <iostream>

// Vehicle class
class Vehicle {
public:
    Vehicle() {
        std::cout << "Vehicle constructor called." << std::endl;
    }
    // drive() is NOT virtual - this prevents polymorphic behavior
    void drive() const { 
        std::cout << "Vehicle is driving." << std::endl;
    }
    // Destructor is also not virtual, a robustness issue for polymorphic deletion
    ~Vehicle() { 
        std::cout << "Vehicle destructor called." << std::endl;
    }
};

// Car class
class Car : public Vehicle {
public:
    Car() {
        std::cout << "Car constructor called." << std::endl;
    }
    // This 'drive' method hides Vehicle's drive, it doesn't override it polymorphically
    void drive() const { 
        std::cout << "Car is driving." << std::endl;
    }
    ~Car() {
        std::cout << "Car destructor called." << std::endl;
    }
};

// SportsCar class
class SportsCar : public Car {
public:
    SportsCar() {
        std::cout << "SportsCar constructor called." << std::endl;
    }
    // This 'drive' method hides Car's drive
    void drive() const {
        std::cout << "SportsCar is driving fast!" << std::endl;
    }
    ~SportsCar() {
        std::cout << "SportsCar destructor called." << std::endl;
    }
};

int main() {
    // Demonstrate constructor order
    std::cout << "\n--- Creating SportsCar object ---" << std::endl;
    SportsCar mySportsCar;

    // Demonstrate method "overriding" (direct call)
    std::cout << "\n--- Demonstrating direct drive() method calls ---" << std::endl;
    mySportsCar.drive(); // Calls SportsCar::drive() directly

    std::cout << "\n--- Using base class pointers for 'polymorphism' (robustness issue here) ---" << std::endl;
    Vehicle* v_ptr = &mySportsCar;
    v_ptr->drive(); // Calls Vehicle::drive() because drive is not virtual

    Car* c_ptr = &mySportsCar;
    c_ptr->drive(); // Calls Car::drive() because drive is not virtual

    std::cout << "\n--- End of program ---" << std::endl;
    return 0;
}