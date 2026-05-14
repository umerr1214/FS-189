#include <iostream>
#include <string>

// The Engine class, demonstrating a robustness issue by not validating input
class Engine {
private:
    int horsepower;
    std::string fuelType;

public:
    // Constructor allows negative horsepower and empty fuel type without validation.
    Engine(int hp, const std::string& ft) : horsepower(hp), fuelType(ft) {
        // No checks for hp > 0 or ft not empty.
        // This can lead to an invalid or nonsensical state for the Engine object.
    }

    int getHorsepower() const { return horsepower; }
    const std::string& getFuelType() const { return fuelType; }

    // This method will print whatever values are stored, including invalid ones.
    void printEngineSpecification() const {
        std::cout << "Engine Horsepower: " << horsepower << ", Fuel Type: " << fuelType << std::endl;
    }
};

// The Car class, which composes an Engine object
class Car {
private:
    std::string make;
    std::string model;
    Engine carEngine; // Composition: Engine is a member of Car

public:
    // Car constructor initializes the Engine member without performing additional validation,
    // thereby inheriting potential robustness issues from the Engine constructor.
    Car(const std::string& mk, const std::string& mdl, int engineHp, const std::string& engineFt)
        : make(mk), model(mdl), carEngine(engineHp, engineFt) {
        // No validation for make/model either, further demonstrating lack of robustness.
    }

    void displayCarDetails() const {
        std::cout << "Car Make: " << make << ", Model: " << model << std::endl;
        std::cout << "  Engine Info: " << std::endl;
        carEngine.printEngineSpecification(); // Access Engine's method to display its properties
    }

    // Car method to access a specific Engine property
    int retrieveEngineHorsepower() const {
        return carEngine.getHorsepower();
    }

    // Car method to access another specific Engine property
    const std::string& retrieveEngineFuelType() const {
        return carEngine.getFuelType();
    }
};

int main() {
    // Test Case 1: A normally constructed car
    Car myCar1("Toyota", "Camry", 180, "Gasoline");
    std::cout << "--- Car 1 Details ---" << std::endl;
    myCar1.displayCarDetails();
    std::cout << "Car 1 Engine Horsepower: " << myCar1.retrieveEngineHorsepower() << std::endl;
    std::cout << "Car 1 Engine Fuel Type: " << myCar1.retrieveEngineFuelType() << std::endl;
    std::cout << std::endl;

    // Test Case 2: A car constructed with invalid engine data, demonstrating the robustness issue.
    // Negative horsepower and empty fuel type are allowed.
    Car myCar2("ElectricCo", "Volt", -50, "");
    std::cout << "--- Car 2 Details (Robustness Issue) ---" << std::endl;
    myCar2.displayCarDetails(); // This will print the invalid data as is.
    std::cout << "Car 2 Engine Horsepower: " << myCar2.retrieveEngineHorsepower() << std::endl;
    std::cout << "Car 2 Engine Fuel Type: " << myCar2.retrieveEngineFuelType() << std::endl;
    std::cout << std::endl;

    // Test Case 3: Another normally constructed car
    Car myCar3("Ford", "F-150", 350, "Diesel");
    std::cout << "--- Car 3 Details ---" << std::endl;
    myCar3.displayCarDetails();
    std::cout << "Car 3 Engine Horsepower: " << myCar3.retrieveEngineHorsepower() << std::endl;
    std::cout << "Car 3 Engine Fuel Type: " << myCar3.retrieveEngineFuelType() << std::endl;
    std::cout << std::endl;

    return 0;
}