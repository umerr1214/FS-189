#include <iostream>
#include <string>

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Parameterized constructor
    Engine(int hp, std::string ft) : horsepower(hp), fuelType(ft) {
        std::cout << "Engine object created with " << hp << " HP and fuel type '" << ft << "'." << std::endl;
    }

    // start method - does not validate state (e.g., horsepower <= 0 or empty fuelType)
    // It will happily report a 0 HP or negative HP engine starting, or one with an empty fuel type.
    void start() const {
        std::cout << "Engine with " << horsepower << " HP and fuel type '" << fuelType << "' started." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Composition

public:
    // Car constructor initializes its Engine
    // Allows construction with potentially invalid engine parameters
    Car(int hp, std::string ft) : engine(hp, ft) {
        std::cout << "Car constructed." << std::endl;
    }

    // Car::start() calls Engine::start()
    void start() {
        std::cout << "Car is attempting to start..." << std::endl;
        engine.start();
    }
};

int main() {
    // Test Case 1: Car with valid engine
    Car myCar(150, "Gasoline");
    myCar.start();
    std::cout << "---" << std::endl;

    // Test Case 2: Car with invalid horsepower (0 HP) - Robustness Issue
    // The engine starts, but a 0 HP engine isn't truly "started" or functional.
    Car brokenCar(0, "Electric");
    brokenCar.start();
    std::cout << "---" << std::endl;

    // Test Case 3: Car with negative horsepower and empty fuel type - Robustness Issue
    // The engine still reports starting, which is misleading.
    Car reallyBrokenCar(-50, "");
    reallyBrokenCar.start();
    std::cout << "---" << std::endl;

    return 0;
}