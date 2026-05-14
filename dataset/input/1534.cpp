#include <iostream>
#include <string>

// Engine class definition
class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor
    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {
        std::cout << "Engine created: " << horsepower << " HP, " << fuelType << std::endl;
    }

    // Methods
    void start() {
        std::cout << "Engine starting (" << horsepower << " HP, " << fuelType << ")..." << std::endl;
    }

    void stop() {
        std::cout << "Engine stopping..." << std::endl;
    }
};

// Car class definition
class Car {
private:
    std::string make;
    std::string model;
    Engine engine; // Composition: Car 'has-a' Engine

public:
    // Constructor for Car, delegating Engine construction
    Car(std::string mk, std::string md, int engineHp, std::string engineFt)
        : make(mk), model(md), engine(engineHp, engineFt) { // Initialize engine member
        std::cout << "Car created: " << make << " " << model << std::endl;
    }

    // Delegate start method to the Engine
    void start() {
        std::cout << make << " " << model << " is attempting to start." << std::endl;
        engine.start();
    }

    // Delegate stop method to the Engine
    void stop() {
        std::cout << make << " " << model << " is attempting to stop." << std::endl;
        engine.stop();
    }
} // SYNTAX ERROR: Missing semicolon after class definition

// Main function (driver)
int main() {
    Car myCar("Toyota", "Camry", 180, "Petrol");
    myCar.start();
    myCar.stop();

    Car anotherCar("Tesla", "Model 3", 450, "Electric");
    anotherCar.start();
    anotherCar.stop();

    return 0;
}