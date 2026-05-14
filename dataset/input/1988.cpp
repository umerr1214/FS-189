#include <iostream>
#include <string>

// Engine class - Readability/Efficiency Issue: Passes std::string by value, potentially inefficient
class Engine {
public:
    // Constructor passes fuelType by value, leading to an unnecessary copy
    Engine(int anEngineHorsepowerValue, std::string theFuelTypeForThisEngine) {
        this->engineHorsepower = anEngineHorsepowerValue; // Excessive use of 'this->'
        this->engineFuelType = theFuelTypeForThisEngine;  // Another unnecessary copy and 'this->'
    }

    int retrieveEngineHorsepower() const { // Verbose method name
        return engineHorsepower;
    }

    // This getter is not const-correct, allowing modification of the internal state via a non-const reference
    std::string& accessEngineFuelType() {
        return engineFuelType;
    }

    void outputEngineDetailsToConsole() const { // Verbose method name
        std::cout << "  Engine Power Rating: " << engineHorsepower << " Horsepower Units" << std::endl; // Verbose output
        std::cout << "  Engine Fuel Source Classification: " << engineFuelType << std::endl; // Verbose output
    }

private:
    int engineHorsepower; // Verbose variable name
    std::string engineFuelType; // Verbose variable name
};

// Car class - Demonstrates composition, also with readability/efficiency issues
class Car {
public:
    // Constructor passes model and engineFt by value, causing unnecessary copies
    Car(std::string carModelName, int carManufactureYear, int enginePowerInput, std::string engineFuelTypeInput)
        : carIdentifierModel(carModelName), // Copy carModelName
          carProductionYear(carManufactureYear),
          containedEngineObject(enginePowerInput, engineFuelTypeInput) // Copy engineFuelTypeInput
    {
        // Empty body, but copies still happen in initializer list.
        // Also, parameters could be const references for efficiency.
    }

    void presentCarAndEngineInformation() const { // Verbose method name
        std::cout << "Vehicle Identifier Model: " << carIdentifierModel << std::endl;
        std::cout << "Vehicle Production Year: " << carProductionYear << std::endl;
        containedEngineObject.outputEngineDetailsToConsole(); // Delegate to Engine's verbose display method
    }

private:
    std::string carIdentifierModel; // Verbose variable name
    int carProductionYear; // Verbose variable name
    Engine containedEngineObject; // Composition
};

int main() {
    // Test cases
    Car firstVehicle("AeroDynamics GT", 2022, 250, "Premium Unleaded");
    std::cout << "--- First Vehicle Information ---" << std::endl;
    firstVehicle.presentCarAndEngineInformation();
    std::cout << std::endl;

    Car secondVehicle("EcoDrive Compact", 2020, 120, "Electric");
    std::cout << "--- Second Vehicle Information ---" << std::endl;
    secondVehicle.presentCarAndEngineInformation();
    std::cout << std::endl;

    // Demonstrate the non-const getter (readability/safety issue)
    std::cout << "Attempting to modify fuel type via non-const getter:" << std::endl;
    Engine tempEngine(10, "Old Fuel");
    std::cout << "Original tempEngine fuel: " << tempEngine.accessEngineFuelType() << std::endl;
    tempEngine.accessEngineFuelType() = "New Fuel"; // This is possible due to non-const getter
    std::cout << "Modified tempEngine fuel: " << tempEngine.accessEngineFuelType() << std::endl;
    std::cout << std::endl;

    return 0;
}