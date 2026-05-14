#include <iostream>
#include <string>
#include <stdexcept> // For potential exceptions if strict validation is needed, though not used here

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor: Uses initializer list and passes fuelType by const reference for efficiency
    Engine(int hp, const std::string& ft)
        : horsepower(hp), fuelType(ft) { // Direct initialization of members
        // Optional: Basic validation during construction for a "correct" engine state
        if (horsepower <= 0) {
            std::cerr << "Warning: Engine initialized with non-positive horsepower (" << horsepower << ")." << std::endl;
        }
        if (fuelType.empty()) {
            std::cerr << "Warning: Engine initialized with empty fuel type." << std::endl;
        }
        std::cout << "Engine object created." << std::endl;
    }

    // start method: Validates state before reporting success, uses const correctness
    void start() const {
        if (horsepower <= 0) {
            std::cout << "ERROR: Engine with " << horsepower << " HP cannot start. Horsepower must be positive." << std::endl;
            return;
        }
        if (fuelType.empty()) {
            std::cout << "ERROR: Engine with empty fuel type cannot start." << std::endl;
            return;
        }
        std::cout << "Engine with " << horsepower << " HP and fuel type '" << fuelType << "' started successfully." << std::endl;
    }
};

class Car {
private:
    Engine engine; // Composition

public:
    // Car constructor: Uses initializer list for the 'engine' member for efficiency and readability
    Car(int hp, const std::string& ft)
        : engine(hp, ft) { // Direct initialization of the engine member
        std::cout << "Car object constructed." << std::endl;
    }

    // Car::start() calls Engine::start()
    void start() {
        std::cout << "Car is attempting to start its engine..." << std::endl;
        engine.start();
    }
};

int main() {
    // Test Case 1: Valid Car and Engine
    Car myCar(250, "Petrol");
    myCar.start();
    std::cout << "---" << std::endl;

    // Test Case 2: Car with engine that has 0 HP (should report error in start())
    Car electricCar(0, "Electric");
    electricCar.start();
    std::cout << "---" << std::endl;

    // Test Case 3: Car with engine that has empty fuel type (should report error in start())
    Car hydrogenCar(180, "");
    hydrogenCar.start();
    std::cout << "---" << std::endl;

    // Test Case 4: Car with negative HP and empty fuel type (should report errors in start())
    Car invalidCar(-100, "");
    invalidCar.start();
    std::cout << "---" << std::endl;

    return 0;
}