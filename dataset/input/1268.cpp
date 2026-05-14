#include <iostream>
#include <string> // Included for demonstrating inefficient string usage

// Vehicle class
class Vehicle {
public:
    Vehicle() {
        // Overly verbose and redundant printing
        std::cout << "------------------------------------------" << std::endl;
        std::cout << "Vehicle constructor is now being executed." << std::endl;
        std::cout << "A new vehicle object is coming to life!" << std::endl;
        std::cout << "------------------------------------------" << std::endl;
    }
    virtual void drive() const {
        // Redundant string construction for printing
        std::string msg = "The magnificent Vehicle is currently in motion. Vroom!";
        std::cout << msg << std::endl;
    }
    virtual ~Vehicle() {
        std::cout << "Vehicle object is being destroyed." << std::endl;
    }
};

// Car class
class Car : public Vehicle {
public:
    Car() {
        // Again, overly verbose and redundant printing
        std::cout << "==========================================" << std::endl;
        std::cout << "Car constructor initiated. Building a car." << std::endl;
        std::cout << "This car inherits from Vehicle." << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    void drive() const override {
        // Redundant string construction for printing
        std::string msg = "The agile Car is navigating the roads. Beep beep!";
        std::cout << msg << std::endl;
    }
    ~Car() override {
        std::cout << "Car object is being destroyed, calling base destructor." << std::endl;
    }
};

// SportsCar class
class SportsCar : public Car {
public:
    SportsCar() {
        // Yet again, overly verbose and redundant printing
        std::cout << "##########################################" << std::endl;
        std::cout << "SportsCar constructor is active. Speed demon ready!" << std::endl;
        std::cout << "This SportsCar inherits from Car." << std::endl;
        std::cout << "##########################################" << std::endl;
    }
    void drive() const override {
        // Redundant string construction for printing
        std::string msg = "The exhilarating SportsCar is driving at incredible speeds! ZOOM!";
        std::cout << msg << std::endl;
    }
    ~SportsCar() override {
        std::cout << "SportsCar object is being destroyed, calling Car destructor." << std::endl;
    }
};

int main() {
    std::cout << "\n--- Commencing object creation sequence for SportsCar ---" << std::endl;
    SportsCar myFastCar; // Object name is a bit verbose too

    std::cout << "\n--- Initiating method execution for drive() across hierarchy ---" << std::endl;
    myFastCar.drive();

    std::cout << "\n--- Demonstrating polymorphic behavior with base pointers ---" << std::endl;
    Vehicle* baseVehiclePtr = &myFastCar; // Verbose pointer name
    baseVehiclePtr->drive();

    Car* baseCarPtr = &myFastCar; // Verbose pointer name
    baseCarPtr->drive();
    
    std::cout << "\n--- Program execution concluded. Deallocating resources. ---" << std::endl;
    return 0;
}