#include <iostream>
#include <string>
#include <stdexcept> // For potential error handling, though simple validation is used here

class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Correct version: Uses initializer list for all members.
    // Adds basic validation for horsepower to ensure a robust object state.
    Engine(int hp, const std::string& ft)
        : horsepower(hp), fuelType(ft) {
        if (horsepower <= 0) {
            std::cerr << "Warning: Engine horsepower must be positive. Setting to default 100 HP." << std::endl;
            horsepower = 100; // Default to a valid positive value for robustness
        }
    }

    void displayEngineInfo() const { // `const` correctness
        std::cout << "  Engine Horsepower: " << horsepower << " HP" << std::endl;
        std::cout << "  Engine Fuel Type: " << fuelType << std::endl;
    }

    int getHorsepower() const { return horsepower; }         // `const` getter
    std::string getFuelType() const { return fuelType; } // `const` getter
};

class Car {
private:
    std::string model;
    Engine carEngine; // Composition

public:
    // Correct version: Uses initializer list for all members, including the composed Engine object.
    Car(const std::string& m, int engine_hp, const std::string& engine_ft)
        : model(m), carEngine(engine_hp, engine_ft) {}

    void displayCarInfo() const { // `const` correctness
        std::cout << "Car Model: " << model << std::endl;
        carEngine.displayEngineInfo();
    }

    const std::string& getModel() const { return model; } // Example of a const getter for model
};

int main() {
    // Standard cases
    Car car1("Sedan X", 150, "Petrol");
    car1.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    Car car2("Sports Y", 300, "Premium Petrol");
    car2.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    // Test with invalid horsepower, demonstrating robust input handling
    Car car3("Economy Z", -10, "Diesel"); // Should trigger horsepower validation
    car3.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    Car car4("City Compact", 0, "Electric"); // Should trigger horsepower validation
    car4.displayCarInfo();
    std::cout << "--------------------" << std::endl;

    return 0;
}