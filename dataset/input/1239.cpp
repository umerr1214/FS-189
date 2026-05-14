#include <iostream>
#include <string>
#include <stdexcept> // Used for robust error handling with exceptions

// The Engine class, demonstrating good practices
class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor with initializer list and input validation for robustness
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {
        if (horsepower <= 0) {
            throw std::invalid_argument("Engine horsepower must be a positive value.");
        }
        if (fuelType.empty()) {
            throw std::invalid_argument("Engine fuel type cannot be empty.");
        }
    }

    // Getter methods with const correctness and efficient string return by const reference
    int getHorsepower() const {
        return horsepower;
    }

    const std::string& getFuelType() const { // Returns by const reference to avoid copying
        return fuelType;
    }

    // Method to display engine information
    void displayEngineInfo() const {
        std::cout << "  Horsepower: " << horsepower << " HP" << std::endl;
        std::cout << "  Fuel Type: " << fuelType << std::endl;
    }
};

// The Car class, which composes an Engine object, demonstrating good practices
class Car {
private:
    std::string make;
    std::string model;
    Engine carEngine; // Composition: Engine object is a member of Car

public:
    // Constructor for Car, using initializer list to construct its members, including the Engine.
    // Delegates engine parameter validation to the Engine class.
    Car(const std::string& mk, const std::string& mdl, int engineHp, const std::string& engineFt)
        : make(mk), model(mdl), carEngine(engineHp, engineFt) {
        // Basic validation for Car's own properties
        if (make.empty() || model.empty()) {
            throw std::invalid_argument("Car make and model cannot be empty.");
        }
    }

    // Method to display car and engine information
    void displayCarInfo() const {
        std::cout << "Car Make: " << make << ", Model: " << model << std::endl;
        std::cout << "Engine Details:" << std::endl;
        carEngine.displayEngineInfo(); // Access Engine's method to display its properties
    }

    // Car method to access a specific Engine property directly
    int getEngineHorsepower() const {
        return carEngine.getHorsepower();
    }

    // Car method to access another specific Engine property directly
    const std::string& getEngineFuelType() const {
        return carEngine.getFuelType();
    }
};

int main() {
    try {
        // Test Case 1: Valid Car object
        Car myCar1("Toyota", "Corolla", 139, "Gasoline");
        std::cout << "--- Car 1 ---" << std::endl;
        myCar1.displayCarInfo();
        std::cout << "Accessed Engine Horsepower via Car: " << myCar1.getEngineHorsepower() << std::endl;
        std::cout << "Accessed Engine Fuel Type via Car: " << myCar1.getEngineFuelType() << std::endl;
        std::cout << std::endl;

        // Test Case 2: Another Valid Car object
        Car myCar2("BMW", "X5", 335, "Petrol");
        std::cout << "--- Car 2 ---" << std::endl;
        myCar2.displayCarInfo();
        std::cout << "Accessed Engine Horsepower via Car: " << myCar2.getEngineHorsepower() << std::endl;
        std::cout << "Accessed Engine Fuel Type via Car: " << myCar2.getEngineFuelType() << std::endl;
        std::cout << std::endl;

        // Test Case 3: Attempt to create a car with invalid engine data (negative horsepower)
        // This should throw an exception due to validation in the Engine constructor.
        std::cout << "--- Attempting to create Invalid Car (negative horsepower) ---" << std::endl;
        try {
            Car invalidCar("InvalidMake", "InvalidModel", -10, "Electric");
            invalidCar.displayCarInfo(); // This line should not be reached
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating car: " << e.what() << std::endl;
        }
        std::cout << std::endl;

        // Test Case 4: Attempt to create a car with invalid engine data (empty fuel type)
        // This should also throw an exception.
        std::cout << "--- Attempting to create Invalid Car (empty fuel type) ---" << std::endl;
        try {
            Car invalidCar2("Nissan", "Leaf", 147, "");
            invalidCar2.displayCarInfo(); // This line should not be reached
        } catch (const std::invalid_argument& e) {
            std::cerr << "Error creating car: " << e.what() << std::endl;
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        // Catch any other unexpected exceptions
        std::cerr << "An unexpected error occurred: " << e.what() << std::endl;
    }

    return 0;
}